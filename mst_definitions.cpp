//
// Created by j473wu on 4/5/2021.
//

#include "mst.h"

//Graph definition:

graph::graph(const int &m) {
    p_vertex = new std::vector<int> [m];
    p_edge = new std::vector<double> [m];
    p_degree = new int [m];
    for(int i = 0; i < m; i++){
        p_degree[i] = 0;
        p_vertex[i].resize(m);
        p_edge[i].resize(m);
    }
    num_edge = 0;
    size = m;
}

graph::~graph() {
    delete []p_vertex;
    p_vertex = nullptr;

    delete []p_edge;
    p_edge = nullptr;

    delete []p_degree;
    p_degree = nullptr;
}

void graph::insert_edge(const int& u, const int& v, const double& w){

    if(!check_adj(u, v)) {
        //Push u and v to each other's vertex matrix to indicate edge existed between them
        p_vertex[u].at(v) = v;
        p_vertex[v].at(u) = u;

        //Push w to u and v 's corresponding edge matrix
        p_edge[u].at(v) = w;
        p_edge[v].at(u) = w;

        //Update the degree array of position u and v
        p_degree[u] = p_degree[u] + 1;
        p_degree[v] = p_degree[v] + 1;

        //Modify the number of edge(an edge is counted twice in undirected graph
        num_edge = num_edge + 2;
    }

    //If edge already existed, update w
    else{
        p_edge[u].at(v) = w;
        p_edge[v].at(u) = w;
    }
}

bool graph::erase_edge(const int& u, const int& v){
    //If no edge existed between u and v, return false
    if(!check_adj(u,v)){
        return false;
    }

    //If there exist an edge, delete edge, update the relationship between u and v
    p_edge[u].at(v) = 0;
    p_edge[v].at(u) = 0;

    p_vertex[u].at(v) = 0;
    p_vertex[v].at(u) = 0;

    p_degree[u] = p_degree[u] - 1;
    p_degree[v] = p_degree[v] - 1;

    num_edge -= 2;

    return true;
}

bool graph::adjacent(const int& u, const int& v, const double& w){
    if(!check_adj(u, v)){
        return false;
    }

    if((p_edge[u].at(v) == w) && (p_edge[v].at(u) == w)){
        return true;
    }

    else return false;
}

int graph::degree(const int& u){
    return p_degree[u];
}

int graph::edge_count(){
    return num_edge;
}

void graph::clear(){
    for(int i = 0; i < size; i++){
        p_vertex[i].clear();
        p_vertex[i].resize(size);

        p_edge[i].clear();
        p_edge[i].resize(size);

        p_degree[i] = 0;
    }
    num_edge = 0;
}

bool graph::mst(const int& r){
    double res = 0;
    pri_queue* p_pq;
    p_pq = new pri_queue(r, size);
    p_pq->build();

    while(!p_pq->empty()){
        node u = p_pq->extract_min();
        if(u.get_key() == std::numeric_limits<double>::max()){
            std::cout << "not connected" << std::endl;
            return false;
        }
        res += u.get_key();
        for(int i = 0; i < adj_list(u.get_g_ind()).size(); i ++){
            int v = adj_list(u.get_g_ind())[i];
            if((p_pq->in_q(v)) && (get_edge(u.get_g_ind(), v) < p_pq->get_node(v)->get_key())){
                p_pq->get_node(v)->set_key(get_edge(u.get_g_ind(), v));
                p_pq->build();
            }
        }
    }

    delete p_pq;
    p_pq = nullptr;

    std::cout << std::fixed << std::setprecision(2) << "mst " << res << std::endl;
    return true;
}

bool graph::check_adj(const int &u, const int &v) {
    if((p_vertex[u].at(v) == v) && (p_vertex[v].at(u) == u) && (u != v)){
        return true;
    }
    else return false;
}

std::vector<int> graph::adj_list(const int& i){
    std::vector<int> res;
    for(int j = 0; j < size; j++){
        if(check_adj(i, j)){
            res.push_back(j);
        }
    }
    return res;
}

double graph::get_edge(const int& u, const int& v){
    return p_edge[u].at(v);
}

int graph::get_size() {
    return size;
}

//node definitions:
node::node(){
    q_ind = 0;
    g_ind = 0;
    key = 0;
    p_parent = nullptr;
}
node::node(int qi, int gi, double k) {
    q_ind = qi;
    g_ind = gi;
    key = k;
    p_parent = nullptr;
}

node::~node(){

}

int node::get_g_ind(){
    return g_ind;
}
double node::get_key(){
    return key;
}

void node::set_key(const double& k){
    key = k;
}

void node::set_parent(node* p){
    p_parent = p;
}

node* node::get_parent(){
    return p_parent;
}

//Priority Queue definitions:
pri_queue::pri_queue(int root, int size){
    q_size = size;
    p_queue = new node [size];
    for(int i = 0; i < size; i++){
        p_queue[i] = node(i + 1, i, 0);
        if(i != root){
            p_queue[i].set_key(std::numeric_limits<double>::max());
        }

    }

}

pri_queue::~pri_queue(){
    delete []p_queue;
    p_queue = nullptr;
}

int pri_queue::parent(const int& i){
    i/2;
}

int pri_queue::left(const int& i){
    return 2*i;
}

int pri_queue::right(const int& i){
    return 2*i + 1;
}

void pri_queue::build(){
    for(int i = q_size/2 - 1; i >= 0; i--){
        heapify(i);
    }
}

bool pri_queue::empty(){
    if(q_size == 0){
        return true;
    }
    else return false;
}

void pri_queue::heapify(const int& i){
    int min = 0;
    int l = left(i + 1) - 1;
    int r = right(i + 1) - 1;

    if((l < q_size) && (p_queue[l].get_key() < p_queue[i].get_key())){
        min = l;
    }
    else min = i;

    if((r < q_size) && (p_queue[r].get_key() < p_queue[min].get_key())){
        min = r;
    }

    if(min != i){
        node temp = p_queue[i];
        p_queue[i] = p_queue[min];
        p_queue[min] = temp;

        heapify(min);
    }

}

node pri_queue::extract_min(){
    node min = p_queue[0];
    p_queue[0] = p_queue[q_size - 1];
    q_size -= 1;
    heapify(0);

    return min;
}

bool pri_queue::in_q(const int& i){
    for(int j = 0; j < q_size; j++){
        if(p_queue[j].get_g_ind() == i){
            return true;
        }
    }
    return false;
}

node* pri_queue::get_node(const int& i){
    for(int j = 0; j < q_size; j++){
        if(i == p_queue[j].get_g_ind()){
            return &p_queue[j];
        }
    }
}


//Illegal exception definitions:

illegal_exception::illegal_exception(const std::string &msg) {
    std::cout << msg << std::endl;
}

illegal_exception::~illegal_exception() {

}