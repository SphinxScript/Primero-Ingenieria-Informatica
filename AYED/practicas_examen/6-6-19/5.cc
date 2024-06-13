void sll_t<T>::insert_head(sll_node_t<T>* n) {
  n->set_next(head_);
  head_ = n;
}


void sll_t<T>::insert_tail(sll_node_t<T>* n) {
  if (empty()) {
    insert_head(n)
  }
  else {
    sll_node_t<T>* aux = head_;
    while (aux->get_next() != NULL) {
      aux = aux->get_next();
    }
    n->set_next(aux->get_next());
    aux->set_next(n);
  }
}


sll_node_t<int>* sll_t<int>::find(const int v) const {
  sll_node_t<int>* aux = head_;
  while (aux != NULL && aux->get_data() != v) {
    aux = aux->get_next();
  }
  return aux;
}

