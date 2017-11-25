/*
 * In c++, there is <type_traits> header
 * this is for obtaining type information on compile-time
 * this code is an example of own trait
 *
 */
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <deque>
#include <unordered_set>
#include <unordered_map>

template <typename T> struct container_traits {
  static bool const value = false;  
};

template <typename... Args>
struct container_traits<std::vector<Args...>> {
  static bool const value = true;
};

template <typename... Args>
struct container_traits<std::deque<Args...>> {
  static bool const value = true;
};

template <typename... Args>
struct container_traits<std::list<Args...>> {
  static bool const value = true;
};

template <typename... Args>
struct container_traits<std::set<Args...>> {
  static bool const value = true;
};

template <typename... Args>
struct container_traits<std::map<Args...>> {
  static bool const value = true;
};

template <typename... Args>
struct container_traits<std::unordered_set<Args...>> {
  static bool const value = true;
};

template <typename... Args>
struct container_traits<std::unordered_map<Args...>> {
  static bool const value = true;
};

template <typename T>
struct is_std {
    static constexpr bool const value = container_traits<T>::value;
};

//example of using is_std in template function
template <typename T>
void func(T param)
{
	//if(is_std<decltype(param)>::value == true)	//origin format
	if(is_std<T>::value == true)
		std::cout << "OK" << std::endl;
	else
		std::cout << "NO" << std::endl;

}

auto main() -> int {
  std::cout << std::boolalpha;
  std::vector<int> v;
  std::cout << is_std<decltype(v)>::value << std::endl;
  std::cout << container_traits<decltype(v)>::value << std::endl;	//this is also OK

  func(v);
  return 0;
}
