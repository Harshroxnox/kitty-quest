#include "spriteAnim.hpp"

SpriteAnim::SpriteAnim(const char* filename, Rectangle SrcRect, Vector2 Position, 
float Scale, Vector2 Origin, float Rotation, Color Tint){

    SpriteTexture = LoadTexture(filename);
    SetTextureFilter(SpriteTexture, TEXTURE_FILTER_TRILINEAR);
    
    this->SrcRect = SrcRect;
    DestRect = (Rectangle){
        Position.x,
        Position.y,
        SrcRect.width*Scale,
        SrcRect.height*Scale,
    };
    this->Origin = Origin;
    this->Rotation = Rotation;
    this->Tint = Tint;
}

void SpriteAnim::Draw(){
    DrawTexturePro(SpriteTexture, SrcRect, DestRect, Origin, Rotation, Tint);
}

void SpriteAnim::Unload(){
    if(IsTextureValid(SpriteTexture)){ 
        UnloadTexture(SpriteTexture);
    }
}

void SpriteAnim::SetScale(float Scale){
    if(Scale > 0){
        DestRect.width = SrcRect.width*Scale;
        DestRect.height = SrcRect.height*Scale;
    }
}
