/*
 * In c++, there is <type_traits> header
 * this is for obtaining type information on compile-time
 * this code is an example of own pointer traits
 *
 */
#include <iostream>
#include <memory>

template <typename T> struct pointer_traits {
  static bool const value = false;  
};

//non-template type should be specialized
template <>
struct pointer_traits<double*> {
  static bool const value = true;
};

template <typename... Args>
struct pointer_traits<std::unique_ptr<Args...>> {
  static bool const value = true;
};

template <typename... Args>
struct pointer_traits<std::shared_ptr<Args...>> {
  static bool const value = true;
};

template <typename T>
struct is_pointer {
    static constexpr bool const value = pointer_traits<T>::value;
};

//example of using is_std in template function
template <typename T>
void func(T& param)
{
	if(is_pointer<T>::value == true)
		std::cout << "OK" << std::endl;
	else
		std::cout << "NO" << std::endl;

}

auto main() -> int {
  std::cout << std::boolalpha;
  std::shared_ptr<int> s(new int);
  //std::cout << is_pointer<decltype(s)>::value << std::endl;
  func(s);

  std::unique_ptr<int> u(new int);
  //std::cout << is_pointer<decltype(s)>::value << std::endl;
  func(u);

  int* ptr = new int(0.0);
  //std::cout << is_pointer<decltype(s)>::value << std::endl;
  func(ptr);
  return 0;
}
