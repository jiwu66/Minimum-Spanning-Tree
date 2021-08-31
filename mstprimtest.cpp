#include <iostream>
#include <vector>
#include "mst.h"

int main() {
    std::string cmdline;
    int m = 0;
    std::getline(std::cin, cmdline);
    int pos = cmdline.find(" ");
    std::string cmd = cmdline.substr(0, pos);

    if(cmd == "n"){
        m = std::stoi(cmdline.substr(pos + 1, cmdline.size() - pos - 1));
        std::cout << "success" << std::endl;
    }
    graph prim(m);

    while(true){
        if(std::cin.eof()){
            break;
        }

        std::getline(std::cin, cmdline);

        if(cmdline == "exit"){
            break;
        }

        int pos = cmdline.find(" ");
        std::string cmd = cmdline.substr(0, pos);

        if(cmd == "edge_count"){
            int res = prim.edge_count();
            std::cout << "edge count is " << res << std::endl;
        }

        if(cmd == "clear"){
            prim.clear();
            std::cout << "success" << std::endl;
        }

        if(cmd == "degree"){
            int u = std::stoi(cmdline.substr(pos + 1, cmdline.size() - pos - 1));

            bool valid = true;
            try{
                if((u >= prim.get_size()) || (u < 0)){
                    throw illegal_exception("illegal argument");
                }
            }
            catch(illegal_exception& e){
                valid = false;
            }

            if(valid) {
                int res = prim.degree(u);
                std::cout << "degree of " << u << " is " << res << std::endl;
            }
        }

        if(cmd == "i"){
            int pos1 = cmdline.find(";");
            int pos2 = cmdline.find(";", pos1 + 1);

            int u = std::stoi(cmdline.substr(pos + 1, pos1 - pos - 1));
            int v = std::stoi(cmdline.substr(pos1 + 1, pos2 - pos1 - 1));
            double w = std::stod(cmdline.substr(pos2 + 1, cmdline.size() - pos2 - 1));

            bool valid = true;
            try{
                if((u >= prim.get_size()) || (v >= prim.get_size()) || (w < 0) || (u == v) || (u < 0) || (v < 0)){
                    throw illegal_exception("illegal argument");
                }
            }
            catch(illegal_exception& e){
                valid = false;
            }

            if(valid) {
                prim.insert_edge(u, v, w);
                std::cout << "success" << std::endl;
            }
        }

        if(cmd == "e"){
            int pos1 = cmdline.find(";");

            int u = std::stoi(cmdline.substr(pos + 1, pos1 - pos - 1));
            int v = std::stoi(cmdline.substr(pos1 + 1, cmdline.size() - pos1 - 1));

            bool valid = true;

            try{
                if((u >= prim.get_size()) || (v >= prim.get_size()) || (u == v) || (u < 0) || (v < 0)){
                    throw illegal_exception("illegal argument");
                }
            }
            catch(illegal_exception &e){
                valid = false;
            }

            if(valid) {
                bool res = prim.erase_edge(u, v);
                if(res){
                    std::cout << "success" << std::endl;
                }
                else std::cout << "failure" << std::endl;
            }
        }

        if(cmd == "adjacent"){
            int pos1 = cmdline.find(";");
            int pos2 = cmdline.find(";", pos1 + 1);

            int u = std::stoi(cmdline.substr(pos + 1, pos1 - pos - 1));
            int v = std::stoi(cmdline.substr(pos1 + 1, pos2 - pos1 - 1));
            double w = std::stod(cmdline.substr(pos2 + 1, cmdline.size() - pos2 - 1));

            bool valid = true;
            try{
                if((u >= prim.get_size()) || (v >= prim.get_size()) || (w < 0) || (u == v) || (u < 0) || (v < 0)){
                    throw illegal_exception("illegal argument");
                }
            }
            catch(illegal_exception& e){
                valid = false;
            }

            if(valid) {
                bool res = prim.adjacent(u, v, w);
                if (res) {
                    std::cout << "adjacent " << std::fixed << std::setprecision(2) << u << " " << v << " " << w
                              << std::endl;
                } else
                    std::cout << "not adjacent " << std::fixed << std::setprecision(2) << u << " " << v << " " << w
                              << std::endl;
            }
        }

        if(cmd == "mst"){
            int u = std::stoi(cmdline.substr(pos + 1, cmdline.size() - pos - 1));

            bool valid = true;
            try{
                if((u >= prim.get_size()) || (u < 0)){
                    throw illegal_exception("illegal argument");
                }
            }
            catch(illegal_exception& e){
                valid = false;
            }

            if(valid) {
                bool res = prim.mst(u);
            }
        }
    }

}
