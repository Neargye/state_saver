// state_saver test_case
//
// Licensed under the MIT License <http://opensource.org/licenses/MIT>.
// Copyright (c) 2018 Daniil Goncharov <neargye@gmail.com>.
//
// Permission is hereby  granted, free of charge, to any  person obtaining a copy
// of this software and associated  documentation files (the "Software"), to deal
// in the Software  without restriction, including without  limitation the rights
// to  use, copy,  modify, merge,  publish, distribute,  sublicense, and/or  sell
// copies  of  the Software,  and  to  permit persons  to  whom  the Software  is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE  IS PROVIDED "AS  IS", WITHOUT WARRANTY  OF ANY KIND,  EXPRESS OR
// IMPLIED,  INCLUDING BUT  NOT  LIMITED TO  THE  WARRANTIES OF  MERCHANTABILITY,
// FITNESS FOR  A PARTICULAR PURPOSE AND  NONINFRINGEMENT. IN NO EVENT  SHALL THE
// AUTHORS  OR COPYRIGHT  HOLDERS  BE  LIABLE FOR  ANY  CLAIM,  DAMAGES OR  OTHER
// LIABILITY, WHETHER IN AN ACTION OF  CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE  OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <utility>

#if defined(TEST_CASE_1)
struct A {
  int i = 0;
  A(int i) : i{i} {}
  A() = default;
  ~A() = default;
  A(A&&) = default;

  A(const A&) = default;
  A& operator=(const A&) = default;
  A& operator=(A&&) = default;
};
#elif defined(TEST_CASE_2)
struct A {
  int i = 0;
  A(int i) : i{i} {}
  A() = default;
  ~A() = default;
  A(A&&) = default;

  A(const A&) = default;
  A& operator=(const A&) = default;
  A& operator=(A&&) = delete;
};
#elif defined(TEST_CASE_3)
struct A {
  int i = 0;
  A(int i) : i{i} {}
  A() = default;
  ~A() = default;
  A(A&&) = default;

  A(const A&) = default;
  A& operator=(A&) = default;
  A& operator=(A&&) = default;
};
#elif defined(TEST_CASE_4)
struct A {
  int i = 0;
  A(int i) : i{i} {}
  A() = default;
  ~A() = default;
  A(A&&) = default;

  A(const A&) = default;
  A& operator=(A&) = default;
  A& operator=(A&&) = delete;
};
#elif defined(TEST_CASE_5)
struct A {
  int i = 0;
  A(int i) : i{i} {}
  A() = default;
  ~A() = default;
  A(A&&) = default;

  A(A&) = default;
  A& operator=(const A&) = default;
  A& operator=(A&&) = default;
};
#elif defined(TEST_CASE_6)
struct A {
  int i = 0;
  A(int i) : i{i} {}
  A() = default;
  ~A() = default;
  A(A&&) = default;

  A(A&) = default;
  A& operator=(const A&) = default;
  A& operator=(A&&) = delete;
};
#elif defined(TEST_CASE_7)
struct A {
  int i = 0;
  A(int i) : i{i} {}
  A() = default;
  ~A() = default;
  A(A&&) = default;

  A(A&) = default;
  A& operator=(A&) = default;
  A& operator=(A&&) = default;
};
#elif defined(TEST_CASE_8)
struct A {
  int i = 0;
  A(int i) : i{i} {}
  A() = default;
  ~A() = default;
  A(A&&) = default;

  A(A&) = default;
  A& operator=(A&) = default;
  A& operator=(A&&) = delete;
};
#elif defined(TEST_CASE_9)
struct A {
  int i = 0;
  A(int i) : i{i} {}
  A() = default;
  ~A() = default;
  A(A&&) = default;

  A(const A&) = default;
  A& operator=(const A& other) noexcept(false) {
    i = other.i;
    return *this;
  }
  A& operator=(A&&) = default;
};
#elif defined(TEST_CASE_10)
struct A {
  int i = 0;
  A(int i) : i{i} {}
  A() = default;
  ~A() = default;
  A(A&&) = default;

  A(const A&) = default;
  A& operator=(const A&) = default;
  A& operator=(A&& other) noexcept(false) {
    i = std::move(other.i);
    return *this;
  }
};
#endif