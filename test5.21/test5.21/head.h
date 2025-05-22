template<typename T> T maximum(const T& A, const T& B) { return A > B ? A : B; }
template<typename T> void swap(T& A, T& B) { A = A + B;B = A - B;A = A - B; }