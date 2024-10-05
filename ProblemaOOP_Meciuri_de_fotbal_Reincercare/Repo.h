//
// Created by Diana on 6/1/2024.
//

#ifndef PROBLEMAOOP_MECIURI_DE_FOTBAL_REPO_H
#define PROBLEMAOOP_MECIURI_DE_FOTBAL_REPO_H

#include<vector>
#include <algorithm>

using namespace std;

template <typename T>
class Repo {
private:
    vector<T> entities;
public:
    Repo();
    ~Repo() = default;
    void addEntity(T&);
    void deleteEntity(T&);
    void updateEntity(T&, T&);
    vector<T> getAll();
    int getSize();
    int findEntity(T&);
};

template<typename T>
Repo<T>::Repo() {}

template<typename T>
void Repo<T>::addEntity(T &entity) {
    entities.push_back(entity);
}

template<typename T>
void Repo<T>::deleteEntity(T &entity) {
    if(findEntity(entity) != -1){
        typename std::vector<T>::iterator it;
        it = find(entities.begin(), entities.end(), entity);
        if(it != entities.end())
            entities.erase(it);
    }
}

template<typename T>
void Repo<T>::updateEntity(T &entity, T &newEntity) {
    int i = findEntity(entity);
    if(i>=0 and i<entities.size())
        entities[i] = newEntity;
}

template<typename T>
vector<T> Repo<T>::getAll() {
    return entities;
}

template<typename T>
int Repo<T>::getSize() {
    return entities.size();
}

template<typename T>
int Repo<T>::findEntity(T &entity) {
    for (int i = 0; i < entities.size(); i++) {
        if (entities[i] == entity)
            return i;
    }
}

#endif //PROBLEMAOOP_MECIURI_DE_FOTBAL_REPO_H
