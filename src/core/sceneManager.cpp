#include "sceneManager.hpp"
#include <stdexcept>
#include <iostream>


SceneManager::SceneManager(){
    if(Scenes.empty()){
        Scenes["Scene1"] = Scene();
        CurrentScene = &Scenes["Scene1"];
    }
}

SceneManager& SceneManager::Get(){
    static SceneManager instance;
    return instance;
}

void SceneManager::RunInternal(){
    if(!CurrentScene){
        throw std::runtime_error("CurrentScene is nullptr");
    }
    // Don't Worry! It will not load again if Scene is already loaded   
    CurrentScene->LoadScene();
    CurrentScene->RunSystems();
}

Scene& SceneManager::GetCurrentSceneInternal(){
    if(!CurrentScene){
        throw std::runtime_error("CurrentScene is nullptr");
    }
    return *CurrentScene;
}

bool SceneManager::AddSceneInternal(const std::string& SceneName){
    if(Scenes.find(SceneName) == Scenes.end()){
        Scenes[SceneName] = Scene();
        return true;
    }else{
        std::cerr<< "SceneName:"<< SceneName <<" must be unique" << std::endl;
        return false;
    }
}

Scene& SceneManager::GetSceneInternal(const std::string& SceneName){
    auto it = Scenes.find(SceneName);

    if(it != Scenes.end()){
        return it->second;
    }else{
        throw std::runtime_error("SceneName:"+ SceneName + " does not exist");
    }
}

bool SceneManager::RemoveSceneInternal(const std::string& SceneName){
    auto it = Scenes.find(SceneName);

    // Scene doesn't exist
    if(it == Scenes.end()){
        std::cerr << "Scene doesn't exist" << std::endl;
        return false;
    }

    // Deny removal of last scene
    if(Scenes.size() == 1){
        std::cerr << "Last Scene! Removal Denied" << std::endl;
        return false;
    }

    // Check if deleted scene is curr scene
    if(CurrentScene == &it->second){
        CurrentScene = &Scenes.begin()->second;
        Scenes.erase(it);
    }else{
        Scenes.erase(it);
    }

    return true;
}

bool SceneManager::SwitchSceneInternal(const std::string& SceneName){
    // check if scene exists
    auto it = Scenes.find(SceneName);
    if(it == Scenes.end()){
        std::cerr << "Scene doesn't exist" << std::endl;
        return false;
    }
  
    // unload the currScene(if applicable)
    if(CurrentScene != nullptr){
        CurrentScene->UnloadScene();
    }

    // update currentScene and load
    CurrentScene = &it->second;
    CurrentScene->LoadScene();
    return true;
}

void SceneManager::Run(){
    Get().RunInternal();
}

Scene& SceneManager::GetCurrentScene(){
    return Get().GetCurrentSceneInternal();
}

bool SceneManager::AddScene(const std::string& SceneName){
    return Get().AddSceneInternal(SceneName);
}

Scene& SceneManager::GetScene(const std::string& SceneName){
    return Get().GetSceneInternal(SceneName);
}

bool SceneManager::RemoveScene(const std::string& SceneName){
    return Get().RemoveSceneInternal(SceneName);
}

bool SceneManager::SwitchScene(const std::string& SceneName){
    return Get().SwitchSceneInternal(SceneName);
}