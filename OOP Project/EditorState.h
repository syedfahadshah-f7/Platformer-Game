#pragma once
#include "State.h"
#include "Button.h"
#include "PauseMenu.h"
#include "TileMap.h"
#include "TextureSelector.h"
#include "Enemies.h"

class EditorState :
    public State
{
private:
    sf::View view;
    sf::Vector2i viewGridPos;

    // Font of the text of main menu
    sf::Font font; 
    sf::Text cursorText;
    PauseMenu* pMenu;

    sf::RectangleShape rectSelector;
    sf::IntRect texRect;

    sf::RectangleShape sidebar;

    // A map to store buttons by their name, this map stores pointers to button
    std::map<std::string, Button*> buttons;

    TileMap* map;
    TextureSelector* texSelector;

    Enemies* enemy_list;

    float viewSpeed;
    bool collision;
    int type;

    // initializing methods
    void initFont();
    void initView();
    void initVariables();
    void initPauseMenu();
    void initSelector();
    void initText();
    void initMap();
    void initEnemyList();
public:
    // Dereference a pointer to State stack pointer as second parameter to have updated stack
    EditorState(StateData* stateData);
    ~EditorState();

    void endState();

    void updateKeybinds(const float& dt);
    void updateView(const float& dt);
    void updateButtons();
    void updatePause(const float& dt);
    void isPausedMenuButtonsPressed();
    void updateCursorText();
    void updateEditorInput();
    void updateGUI(const float& dt);
    void update(const float& dt);

    void renderButtons(sf::RenderTarget* target);
    void renderGUI(sf::RenderTarget* target);
    void render(sf::RenderTarget* target);
};

