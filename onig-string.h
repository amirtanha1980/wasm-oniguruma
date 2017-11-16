#ifndef SRC_ONIG_STRING_H_
#define SRC_ONIG_STRING_H_

#include <emscripten/emscripten.h>
#include <emscripten/bind.h>

class OnigString {
 public:
  OnigString(char* utf8Value, size_t utf16_length);
  ~OnigString();

  const char* utf8_value() const { return utf8Value; }
  size_t utf8_length() const { return utf8_length_; }

  int ConvertUtf8OffsetToUtf16(int utf8Offset);
  int ConvertUtf16OffsetToUtf8(int utf16Offset);

 private:
  char* utf8Value;
  size_t utf8_length_;
  bool hasMultiByteChars;

  size_t utf16_length_;
  int *utf16OffsetToUtf8;
  int *utf8OffsetToUtf16;
};

#endif  // SRC_ONIG_STRING_H_
