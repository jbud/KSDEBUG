#include <KSDEBUG.h>
KSDEBUG debug;

void setup() {
  debug.init();
}

void loop() {
  debug.writeln("Hello World!");
}
