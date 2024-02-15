#include "library.hpp"

#include "Magnum/GL/Shader.h"
#include "Magnum/Shaders/FlatGL.h"
#include "Magnum/GL/Renderer.h"
#include "Magnum/GL/Context.h"

using namespace Magnum;

void sayHello() {
  Magnum::Shaders::FlatGL2D shader { Magnum::NoCreate };
  
  printf("Hello world\n");
};

