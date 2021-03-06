#ifndef DEQUE_H_
#define DEQUE_H_
#define offset(type, member) (intptr_t)(&((type *)0)->member)
#define NODE_ENTRY(struct_type, member_name, ptr) \
  (struct_type *)((intptr_t)ptr - offset(struct_type, member_name))
struct deque_node {
  struct deque_node * prev;
  struct deque_node * next;
};
struct deque {
  struct deque_node first;
  struct deque_node last;
};
void deque_init(struct deque * deque);

void deque_push_front(struct deque * deque, struct deque_node * node);
void deque_push_back(struct deque * deque, struct deque_node * node);
struct deque_node * deque_pop_front(struct deque * deque);
struct deque_node * deque_pop_back(struct deque * deque);

// return itself
struct deque_node * deque_remove(struct deque_node * node);

// insert src in front of dest
void deque_insert(struct deque_node * dest, struct deque_node * src);

int deque_empty(struct deque * deque);

// check if the node is in the deque
int deque_exist(struct deque * deq, struct deque_node * node);
#endif
