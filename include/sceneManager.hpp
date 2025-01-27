# pragma once
#include "scene.hpp"
#include <string>
#include <unordered_map>

/* The SceneManager:-
Is responsible for running, loading, unloading, switching scenes 
It stores all scenes in an unordered map
It is also responsible for adding, removing and keeping track of current scene
*/

class SceneManager {
    public:
        // Singleton stuff
        SceneManager(const SceneManager&) = delete;

        // Main API
        // Run always runs the current scene
        static void Run();
        static SceneManager& Get();
        static Scene& GetCurrentScene();
        static bool AddScene(const std::string& SceneName);
        static Scene& GetScene(const std::string& SceneName);
        static bool RemoveScene(const std::string& SceneName);
        // NOTE: SwitchScene only handles the loading and unloading you still have to 
        // run the scene using Run()
        static bool SwitchScene(const std::string& SceneName);
        
    private:
        // The internal non-static functions 
        void RunInternal();
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