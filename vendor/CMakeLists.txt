# {fmt}
target_sources(
  ${fmt_project}
  PRIVATE "fmt/include/fmt/args.h"
          "fmt/include/fmt/chrono.h"
          "fmt/include/fmt/color.h"
          "fmt/include/fmt/compile.h"
          "fmt/include/fmt/core.h"
          "fmt/include/fmt/format-inl.h"
          "fmt/include/fmt/format.h"
          "fmt/include/fmt/os.h"
          "fmt/include/fmt/ostream.h"
          "fmt/include/fmt/printf.h"
          "fmt/include/fmt/ranges.h"
          "fmt/include/fmt/std.h"
          "fmt/include/fmt/xchar.h"
          "fmt/src/fmt.cc"
          "fmt/src/format.cc"
          "fmt/src/os.cc")

target_include_directories(${fmt_project} PUBLIC "fmt/include")
