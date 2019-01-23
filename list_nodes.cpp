// ref: Scott ML, Programming Pragmatics, Examples 9.1 and 9.2

class list_err{ //exception
 public:
  char *description;
  list_err(char *s) {description = s;}
}

class list_node {
  list_node* prev;
  list_node* next;
  list_node* head_node;
 public:
  int val; // actual data in the node
  list_node(){ // constructor
   prev = next = head_node = this; //point to self
   val = 0; //default value
  }
  list_node* predecessor(){
   if (prev == this || prev == head_node) return 0;
   return prev;
  }
  list_node* predecessor(){
   if (next == this || next == head_node) return 0;
   return next;
  }
  bool singleton(){ return (prev == this); } 
  void insert_before(list_node* new_node){
   if (!new_node->singleton()) 
    throw new list_err("attempt to insert node already onn list");
   prev->next = new_node;
   new_node->next = this;
   prev = new_node;
   new_node->head_node = head_node;
  }
 
  void remove(){
   if(singleton())
    throw new list_err("attempt to remove node not currently on list");
   prev->next=next;
   next->prev=prev;
   prev=next=head_node=this; //point to self
  }
 
  ~list_node(){ //destructor
   if(!singleton())
    throw new list_err("attempt to delete node still on list");
  }
}; // list_node definition over

class list {
 list_node header;
 public:
  // no explicit constructor required; implicit construction of header suffices
  int empty(){ return header.singleton(); }
  list_node* head(){ return header.successor(); }
  void append(list_node *new_node){ header.insert_before(new_node); }
  ~list() { //destructor
   if(!header.singleton())
    throw new list_err("attempt to delete non-empty list");
  }
};
   
// [ done on 23/1/19 from 8am to 9am ]
