#include "saves.hpp"

template<typename Archive>
void serialize(Archive &archive, vec2int vec){
    archive(
        make_nvp("x", vec.x),
        make_nvp("y", vec.y)
    );
}

template<typename Archive>
void serialize(Archive &archive, SDL_Color color){
    archive(
        make_nvp("r", color.r),
        make_nvp("g", color.g),
        make_nvp("b", color.b),
        make_nvp("a", color.a)
    );
}

template<typename Archive>
void serialize(Archive &archive, GridSpatial &gridSpatial){
    archive(
        make_nvp("position", gridSpatial.position)
    );
}

template<typename Archive>
void load_and_construct(Archive &archive, construct<GridSpatial> &construct){
    vec2int vec;
    archive(vec);
    construct(vec);

    // grid placement stuff
}

template<typename Archive>
void serialize(Archive &archive, Collider &collider){
    archive(
        make_nvp("weight", collider.weight)
    );
}

template<typename Archive>
void serialize(Archive &archive, Looks &looks){
    archive(
        make_nvp("text", looks.text),
        make_nvp("font", looks.font),
        make_nvp("size", looks.size),
        make_nvp("foreground", looks.foreground),
        make_nvp("background", looks.background)
    );
}

void save(registry& registry, stringstream& storage){
    JSONOutputArchive output{storage};

    snapshot{registry}.entities(output).component<GridSpatial, Collider, Looks>(output);
}

void restore(registry& registry, stringstream& storage){
    JSONInputArchive input{storage};
    snapshot_loader{registry}.entities(input).component<GridSpatial, Collider, Looks>(input);
}

void save_to_file(registry& registry, string filename){
    stringstream storage;
    ofstream fout;
    save(registry, storage);

    fout.open(filename);
    fout << storage.rdbuf(); // .str()
    fout.close();
}

void restore_from_file(registry& registry, string filename){
    stringstream storage;
    std::ifstream fin;

    fin.open(filename);
    storage << fin.rdbuf();
    fin.close();

    restore(registry, storage);
}