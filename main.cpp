#include <iostream>
#include <cassert>
#include <string>
#include <vector>

/// Implementation of int_to_word main function
int do_main(const std::vector<std::string>& args)
{
  if (args.size() != 2)
  {
    return 1;
  }
  try
  {
    const int value{std::stoi(args[1])};
    switch (value)
    {
      case 1: std::cout << "one\n"; break;
      case 2: std::cout << "two\n"; break;
      case 3: std::cout << "three\n"; break;
      case 4: std::cout << "four\n"; break;
      case 5: std::cout << "five\n"; break;
      case 6: std::cout << "six\n"; break;
      default: throw std::invalid_argument("value must be in range [1, 6]");
    }
  }
  catch (const std::exception&)
  {
    return 1;
  }
  return 0;
}

/// bool_to_coin main function, that also tests its implementation
int main(int argc, char* argv[])
{
    assert(do_main( { "int_to_word" } ) == 1);
    assert(do_main( { "int_to_word", "1" } ) == 0);
    assert(do_main( { "int_to_word", "2" } ) == 0);
    assert(do_main( { "int_to_word", "3" } ) == 0);
    assert(do_main( { "int_to_word", "4" } ) == 0);
    assert(do_main( { "int_to_word", "5" } ) == 0);
    assert(do_main( { "int_to_word", "6" } ) == 0);
    assert(do_main( { "int_to_word", "nonsense" } ) == 1);
    assert(do_main( { "int_to_word", "1 2" } ) == 1);

    const std::vector<std::string> args (argv, argv + argc);
    return do_main(args);
}
