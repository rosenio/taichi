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
#include "taichi/ui/ggui/app_context.h"
#include "taichi/ui/ggui/renderable.h"
#include "taichi/ui/ggui/scene.h"
#include "taichi/ui/ggui/swap_chain.h"

namespace taichi::ui {

namespace vulkan {

class Particles final : public Renderable {
public:
  Particles(AppContext *app_context, VertexAttributes vbo_attrs);

  void update_data(const ParticlesInfo &info);

  void update_scene_data(DevicePtr ssbo_ptr, DevicePtr ubo_ptr) override;

  void record_this_frame_commands(lang::CommandList *command_list) override;

private:
  DevicePtr lights_ssbo_ptr;
  DevicePtr scene_ubo_ptr;

  struct UBORenderable {
    alignas(16) glm::vec3 color;
    int use_per_vertex_color;
    int use_per_vertex_radius;
    float radius;
  };
};

} // namespace vulkan

} // namespace taichi::ui
