#include "LVLMNGR.H"
#include "RENDERER.H"
#include "LEVELS.H"

static void lmCreate(LevelManager* self);
static void lmDrawCurrentLevel(const LevelManager* self);
static GameLevel* lmGetCurrentLevel(LevelManager* self);
static void lmLoadNextLevel(LevelManager* self);

void lmInit(LevelManager* self) {
    self->new = lmCreate;
    self->drawCurrentLevel = lmDrawCurrentLevel;
    self->getCurrentLevel = lmGetCurrentLevel;
    self->loadNextLevel = lmLoadNextLevel;

    self->currentLevelIndex = 0;
}

static void lmCreate(LevelManager* self) {
    GameLevel one, two, three, four;
    
    glInit(&one);
    one.new(&one, levelOne);
    self->levels[0] = one;

    glInit(&two);
    two.new(&two, levelTwo);
    self->levels[1] = two;

    glInit(&three);
    three.new(&three, levelThree);
    self->levels[2] = three;

    glInit(&four);
    four.new(&four, levelFour);
    self->levels[3] = four;
    
    self->currentLevelIndex = 0;
}

static void lmDrawCurrentLevel(const LevelManager* self) {
    const GameLevel* currentLevel = &self->levels[self->currentLevelIndex];
    currentLevel->draw(currentLevel);
}

static GameLevel* lmGetCurrentLevel(LevelManager* self) {
    return &self->levels[self->currentLevelIndex];
}

static void lmLoadNextLevel(LevelManager* self) {
    ++self->currentLevelIndex;

    if (self->currentLevelIndex > 3) {
        self->currentLevelIndex = 0;
    }
}