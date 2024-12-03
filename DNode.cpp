#include <stdlib.h>
using namespace std;

#include "DNode.hpp"

DNode::DNode(){
    song = NULL;
    next = NULL;
    prev = NULL;
}

DNode::DNode(string s, string a, int lenmin, int lensec){
    song = new Song(s,a,lenmin,lensec);
    next = NULL;
    prev = NULL;
}