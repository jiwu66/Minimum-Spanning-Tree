//
// Created by j473wu on 4/4/2021.
//

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <iomanip>
class graph{
private:
    std::vector<int> *p_vertex;
    std::vector<double> *p_edge;
    int *p_degree;
    int num_edge;
    int size;

public:
    graph(const int& m);
    ~graph();
    void insert_edge(const int& u, const int& v, const double& w);
    bool erase_edge(const int& u, const int& v);
    bool adjacent(const int& u, const int& v, const double& w);
    int degree(const int& u);
    int edge_count();
    void clear();
    bool mst(const int& r);
    bool check_adj(const int& u, const int&v);
    std::vector<int> adj_list(const int& i);
    double get_edge(const int& u, const int& v);
    int get_size();
};

class node{
private:
    int q_ind;
    int g_ind;
    double key;
    node* p_parent;
public:
    node();
    node(int qi, int gi, double k);
    ~node();
    int get_g_ind();
    double get_key();
    node* get_parent();
    void set_key(const double& k);
    void set_parent(node *p);
};

class pri_queue{
private:
    node* p_queue;
    int q_size;
public:
    pri_queue(int root, int size);
    ~pri_queue();
    int parent(const int& i);
    node* get_node(const int& i);
    int left(const int& i);
    int right(const int& i);
    void build();
    bool empty();
    void heapify(const int& i);
    node extract_min();
    bool in_q(const int& i);
};

class illegal_exception{
private:
    std::string msg;
public:
    illegal_exception(const std::string& msg);
    ~illegal_exception();
};