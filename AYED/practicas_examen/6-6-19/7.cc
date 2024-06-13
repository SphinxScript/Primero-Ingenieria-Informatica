void sll_union(sll_t<int>& A, sll_t<int>& B, sll_t<int>& C) {
  sll_node_t<int>* aux = A.head_();
  while (aux != NULL) {
    if (B.find(aux->get_data()) != NULL) {
      C.insert_tail(new sll_node_t<int>(aux->get_data()))
    }
    aux = aux->get_next();
  }
}