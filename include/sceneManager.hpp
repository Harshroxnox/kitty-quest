# pragma once
#include "scene.hpp"
#include <string>
#include <unordered_map>

class SceneManager {
    public:
        // Singleton stuff
        SceneManager(const SceneManager&) = delete;

        // Main API
        static SceneManager& Get();
        static Scene& GetCurrentScene();
        static bool AddScene(const std::string& SceneName);
        static Scene& GetScene(const std::string& SceneName);
        static bool RemoveScene(const std::string& SceneName);
        static bool SwitchScene(const std::string& SceneName);
        
    private:
        // The internal non-static functions 
        Scene& GetCurrentSceneInternal();
        bool AddSceneInternal(const std::string& SceneName);
        Scene& GetSceneInternal(const std::string& SceneName);
        bool RemoveSceneInternal(const std::string& SceneName);
        bool SwitchSceneInternal(const std::string& SceneName);

        // Private variables
        Scene* CurrentScene = nullptr;
        std::unordered_map<std::string, Scene> Scenes;
        
        // Singleton stuff
        SceneManager();
};