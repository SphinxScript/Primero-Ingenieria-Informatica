double operator*(const sparse_vector_t& a, const sparse_vector_t& b) {
  assert(a.get_n() == b.get_n());
  double scalar = 0.0;
  int i = 0;
  const int a_sz = a.get_nz();
  int k = 0;
  const int b_sz = a.get_nz();
  while (i < a_sz && k < b_sz) {
    if (a[i].get_inx() == b[k].get_inx()) {
      scalar += a[i].get_data() * b[k].get_data();
      ++i;
      ++k;
    }
    else if(a[i].get_inx() > b[k].get_inx()) {
      ++k;
    }
    else {
      ++i;
    }
  }
  return scalar;
}