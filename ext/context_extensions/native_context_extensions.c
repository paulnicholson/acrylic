#include "ruby.h"
#include <stdlib.h>
#include <cairo.h>
#include <rb_cairo.h>
#include <intern.h>

static VALUE method_paint_with_alpha(VALUE self, VALUE _alpha) {
  double alpha = NUM2DBL(_alpha);

  cairo_t *cr = RVAL2CRCONTEXT(self);
  cairo_paint_with_alpha(cr, alpha);
  return Qnil;
}

void Init_native_context_extensions() {
  VALUE cKlass = rb_cObject;
  cKlass = rb_const_get(cKlass,rb_intern("Cairo"));
  cKlass = rb_const_get(cKlass,rb_intern("Context"));
  rb_define_method(cKlass, "paint_with_alpha", (VALUE(*)(ANYARGS))method_paint_with_alpha, 1);
}
