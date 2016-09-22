/**
* Copyright 2016 BitTorrent Inc.
* 
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
* 
*    http://www.apache.org/licenses/LICENSE-2.0
* 
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
#pragma once

#include "scraps/config.h"

#include "scraps/opengl/opengl.h"
#include "scraps/opengl/VertexBuffer.h"

namespace scraps {
namespace opengl {

#if OPENGL_ES && !SCRAPS_IOS && !SCRAPS_TVOS
// for now we need to emulate this for opengl es
// TODO: use extension for android? (some vendor implementations are allegedly crashy...)
#define SCRAPS_EMULATE_VERTEX_ARRAY 1
#endif

class VertexArray {
public:
    VertexArray();
    ~VertexArray();

    void bind();
    void unbind();

    void setAttribute(GLuint index, VertexBuffer& buffer, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLuint offset);

private:
#if SCRAPS_EMULATE_VERTEX_ARRAY
    std::vector<std::tuple<GLuint, GLuint, GLint, GLenum, GLboolean, GLsizei, GLuint>> _attributes;
#else
    GLuint _object = 0;
#endif
};

} // namespace opengl
} // namespace scraps
