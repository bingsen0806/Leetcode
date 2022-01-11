#include <unordered_map>
using namespace std;

class LRUCache {
public:
    class Node{
        public:
        int key, val;
        Node *next, *prev;
        Node(int KEY, int VAL){
            key=KEY; val=VAL;
        }
    };
    Node *head=new Node(-1, -1);
    Node *tail=new Node(-1, -1);
    unordered_map<int, Node *> mp;
    int cap;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void addNode(Node *newNode){
        Node *temp=head->next;
        newNode->next=temp;
        newNode->prev=head;
        head->next=newNode;
        temp->prev=newNode;
    }
    void deleteNode(Node *delNode){
        Node *delPrev=delNode->prev;
        Node *delNext=delNode->next;
        delPrev->next=delNext;
        delNext->prev=delPrev;
    }
    int get(int key) {
        if(mp.find(key) != mp.end()){
            Node *resNode=mp[key];
            int res=resNode->val;
            
            deleteNode(resNode);
            mp.erase(key);
            
            addNode(resNode);
            mp[key]=head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node *existingNode=mp[key];
            deleteNode(existingNode);
            mp.erase(key);
        }
        if(mp.size()==cap){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key, value));
        mp[key]=head->next;
    }
};