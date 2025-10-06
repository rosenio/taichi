#pragma once

#include "taichi/ui/ggui/vertex.h"
#include "taichi/ui/utils/utils.h"
#include <algorithm>
#include <array>
#include <chrono>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <optional>
#include <set>
#include <stdexcept>
#include <vector>

#include "taichi/program/field_info.h"
#include "taichi/ui/common/canvas_base.h"
#include "taichi/ui/ggui/app_context.h"
#include "taichi/ui/ggui/renderable.h"
#include "taichi/ui/ggui/swap_chain.h"

namespace taichi::ui {

namespace vulkan {

class Circles final : public Renderable {
public:
  Circles(AppContext *app_context, VertexAttributes vbo_attrs);
  void update_data(const CirclesInfo &info);

  void record_this_frame_commands(lang::CommandList *command_list) override;

private:
  struct UniformBufferObject {
    alignas(16) glm::vec3 color;
    int use_per_vertex_color;
    int use_per_vertex_radius;
    float radius;
    float window_width;
    float window_height;
  };
};

} // namespace vulkan

} // namespace taichi::ui
