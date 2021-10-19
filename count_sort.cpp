void count_sort(vector < unsigned > & array) {
  size_t n = array.size();
  vector < unsigned > counts(n, 0);
  for (size_t i = 0; i < n− 1; i++) {
    for (size_t j = i + 1; j < n; j++) {
      if (array.at(i) < array.at(j)) {
        counts.at(j) ++;
      } else {
        counts.at(i) ++;
      }
    }
  }
  vector < unsigned > copy = array;
  for (size_t i = 0; i < n; i++) {
    array.at(counts.at(i)) = copy.at(i);
  }
}
