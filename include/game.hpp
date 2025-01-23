#pragma once 

class Game {
    public:
        Game(const Game&) = delete;
        static Game& Get();
        static void Init();
        static void Run();
    private:
        void InitInternal();
        void RunInternal();
        Game() {}
};