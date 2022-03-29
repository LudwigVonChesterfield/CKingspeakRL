#include <sstream>
#include <fstream>
#include <cereal/archives/json.hpp>
#include <entt/entt.hpp>
#include <SDL2/SDL.h>
#include "components.hpp"

using entt::registry;
using entt::entity;
using entt::snapshot;
using entt::snapshot_loader;
using std::stringstream;
using std::ifstream;
using std::ofstream;
using cereal::JSONOutputArchive;
using cereal::JSONInputArchive;
using cereal::construct;
using cereal::make_nvp;

void save(registry& registry, stringstream& storage);
void save_to_file(registry& registry, string filename);

void restore(registry& registry, stringstream& storage);
void restore_from_file(registry& registry, string filename);
