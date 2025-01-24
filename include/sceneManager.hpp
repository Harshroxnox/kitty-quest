# pragma once
#include "scene.hpp"
#include <string>
#include <unordered_map>

class SceneManager {
    public:
        // Singleton stuff
        static SceneManager& Get();
        SceneManager(const SceneManager&) = delete;

        // Main API 
        static Scene& GetCurrentScene();
        static void AddScene(std::string SceneName);
        static Scene& GetScene(std::string SceneName);
        static void RemoveScene(std::string SceneName);
        static void SwitchScene(std::string SceneName);
        
    private:
        // The internal non-static functions 
        Scene& GetCurrentSceneInternal();
        void AddSceneInternal(std::string SceneName);
        Scene& GetSceneInternal(std::string SceneName);
        void RemoveSceneInternal(std::string SceneName);
        void SwitchSceneInternal(std::string SceneName);

        // Private variables
        Scene* CurrentScene = nullptr;
        std::unordered_map<std::string, Scene> Scenes;
        
        // Singleton stuff
        SceneManager() {}
};