#ifndef UTILS_TO_STRING_H
#define UTILS_TO_STRING_H
#include <string>
#include <sstream>

namespace utils {
  /**
   * Credits
   * https://www.fluentcpp.com/2017/06/06/using-tostring-custom-types-cpp/
   */

  template<typename...>
  using try_to_instantiate = void;

  using disregard_this = void;

  template<template<typename...> class Expression, typename Attempt, typename... Ts>
  struct is_detected_impl : std::false_type{};

  template<template<typename...> class Expression, typename... Ts>
  struct is_detected_impl<Expression, try_to_instantiate<Expression<Ts...>>, Ts...> : std::true_type{};

  template<template<typename...> class Expression, typename... Ts>
  constexpr bool is_detected = is_detected_impl<Expression, disregard_this, Ts...>::value;

  // 1- detecting if std::to_string is valid on T
  template<typename T>
  using std_to_string_expression = decltype(std::to_string(std::declval<T>()));

  template<typename T>
  constexpr bool has_std_to_string = is_detected<std_to_string_expression, T>;

  // 2- detecting if to_string is valid on T
  template<typename T>
  using to_string_expression = decltype(to_string(std::declval<T>()));

  template<typename T>
  constexpr bool has_to_string = is_detected<to_string_expression, T>;

  // 3- detecting T can be sent to an ostringstream
  template<typename T>
  using ostringstream_expression = decltype(std::declval<std::ostringstream&>() << std::declval<T>());

  template<typename T>
  constexpr bool has_ostringstream = is_detected<ostringstream_expression, T>;

  // 1-  std::to_string is valid on T
  template<typename T, typename std::enable_if<has_std_to_string<T>, int>::type = 0>
  inline std::string to_string(T const& t) {
      return std::to_string(t);
  }

  // 2-  std::to_string is not valid on T, but to_string is
  template<typename T, typename std::enable_if<!has_std_to_string<T> && has_to_string<T>, int>::type = 0>
  inline std::string to_string(T const& t) {
      return to_string(t);
  }

  // 3-  neither std::string nor to_string work on T, let's stream it then
  template<typename T, typename std::enable_if<!has_std_to_string<T> && !has_to_string<T> && has_ostringstream<T>, int>::type = 0>
  inline std::string to_string(T const& t) {
      std::ostringstream oss;
      oss << t;
      return oss.str();
  }

  inline std::string to_string(char const& ch) {
    std::string s(1, ch);
    return s;
  }

  inline std::string to_string (bool const& b) {
    return (b == true ? "true" : "false");
  }
} // utils

#endif
