size_t binary_search(const vector < unsigned > & array,
  unsigned value_to_find,
  size_t left, size_t right) {
  size_t n = array.size();
  if (left <= right && right < n) {
    size_t mid = (left + right) / 2;
    if (array.at(mid) < value_to_find) {
      return binary_search(array, value_to_find, mid + 1, right);
    } else if (array.at(mid) > value_to_find) {
      return binary_search(array, value_to_find, left, mid− 1);
    } else {
      return mid; // found
    }
  }
  return array.size(); // not found
}
