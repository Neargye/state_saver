// state_saver examples
//
// Licensed under the MIT License <http://opensource.org/licenses/MIT>.
// SPDX-License-Identifier: MIT
// Copyright (c) 2018 - 2019 Daniil Goncharov <neargye@gmail.com>.
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

#include <state_saver.hpp>

#include <iostream>

void foo1(int& a) {
  STATE_SAVER_EXIT(a); // State saver.

  a = 1;
  std::cout << "foo1 a = " << a << std::endl;
}

void foo2(int& a) {
  MAKE_STATE_SAVER_EXIT(state_saver, a); // Custom state saver.

  a = 2;
  std::cout << "foo2 a = " << a << std::endl;
}

void foo3(int& a) {
  yal::state_saver_exit<decltype(a)> state_saver{a}; // Custom state saver.

  a = 3;
  std::cout << "foo3 a = " << a << std::endl;
}

void foo4(int& a) {
  MAKE_STATE_SAVER_EXIT(state_saver, a); // Custom state saver.

  a = 4;
  std::cout << "foo4 a = " << a << std::endl;

  state_saver.dismiss(); // Dismiss, state will not automatically restored.
  std::cout << "foo4 dismiss restore" << std::endl;
}

void foo5(int& a) {
  MAKE_STATE_SAVER_EXIT(state_saver, a); // Custom state saver.

  a = 5;
  std::cout << "foo5 a = " << a << std::endl;

  state_saver.dismiss(); // Dismiss, state will not automatically restored.
  std::cout << "foo5 dismiss restore" << std::endl;

  state_saver.restore(/*force:*/ true); // Restore force state.
  std::cout << "foo5 force restore" << std::endl;
  std::cout << "foo5 a = " << a << std::endl;
}

void foo6(int& a) {
  MAKE_STATE_SAVER_EXIT(state_saver, a); // Custom state saver.

  a = 6;
  std::cout << "foo6 a = " << a << std::endl;

  state_saver.dismiss(); // Dismiss, state will not automatically restored.
  std::cout << "foo6 dismiss restore" << std::endl;

  state_saver.restore(/*force:*/ false); // Restore state if not dismiss.
  std::cout << "foo6 restore" << std::endl;
  std::cout << "foo6 a = " << a << std::endl;
}

int main() {
  int a = 0;
  std::cout << "main a = " << a << std::endl;

  foo1(a);
  std::cout << "main a = " << a << std::endl;

  foo2(a);
  std::cout << "main a = " << a << std::endl;

  foo3(a);
  std::cout << "main a = " << a << std::endl;

  foo4(a);
  std::cout << "main a = " << a << std::endl;

  foo5(a);
  std::cout << "main a = " << a << std::endl;

  foo6(a);
  std::cout << "main a = " << a << std::endl;

  return 0;
}
