#ifndef __KNIGHT2_H__
#define __KNIGHT2_H__

#include "main.h"

// #define DEBUG
class BaseKnight;
class BaseItem;
class Events;
class BaseOpponent;
enum ItemType {
    antidote,
    phoenixdownI,
    phoenixdownII,
    phoenixdownIII,
    phoenixdownIV

};

class BaseBag {
public:
    BaseKnight *knight=NULL;
    BaseItem *head =NULL;
    int size = 0, Limited = 0;
    int fail;
    void checkHp();
    ~BaseBag();
    virtual bool insertFirst(BaseItem *item);
    BaseItem *get(ItemType itemType);
    void remove();
    virtual string toString() const;
    
};
class PaladinBag : public BaseBag{
public:
    PaladinBag(BaseKnight *knight, int a, int b);
};
class LancelotBag : public BaseBag{
public:
    LancelotBag(BaseKnight *knight, int a, int b);
};
class NormalBag : public BaseBag{
public:
    NormalBag(BaseKnight *knight, int a, int b);
};
class DragonBag : public BaseBag{
public:
    DragonBag(BaseKnight *knight, int a, int b);
};
enum OpponentType {
    MadBear=1, Bandit, LordLupin, Elf, Troll, Tornbery, QueenOfCards, 
    NinaDeRings, DurianGarden, OmegaWeapon, Hades
};
class BaseOpponent{
    public:
    static bool toOmegaWeapon; 
    static bool toHades;
protected:
    int a;
public:
    static BaseOpponent * create(int a, OpponentType opponentType);
    virtual void updateKnight(BaseKnight *knight) = 0;
    virtual OpponentType Type() = 0;
};
//sk1
class MadBearOpponent: public BaseOpponent{
public:
    MadBearOpponent(){}
    OpponentType Type();
    void updateKnight(BaseKnight *knight);
};
//sk2
class BanditOpponent: public BaseOpponent{
public:
    BanditOpponent(){}
    OpponentType Type();
    void updateKnight(BaseKnight *knight);
};
//sk3
class LordLupinOpponent: public BaseOpponent{
public:
    LordLupinOpponent(){}
    OpponentType Type();
    void updateKnight(BaseKnight *knight);
};
//sk4
class ElfOpponent: public BaseOpponent{
public:
    ElfOpponent(){}
    OpponentType Type();
    void updateKnight(BaseKnight *knight);
};
//sk5
class TrollOpponent: public BaseOpponent{
public:
    TrollOpponent(){}
    OpponentType Type();
    void updateKnight(BaseKnight *knight);
};
//sk6
class TornberyOpponent: public BaseOpponent{
public:
    TornberyOpponent(){}
    OpponentType Type();
    void updateKnight(BaseKnight *knight);
};
//sk7
class QueenOfCardsOpponent: public BaseOpponent{
public:
    QueenOfCardsOpponent(){}
    OpponentType Type();
    void updateKnight(BaseKnight *knight);
};
//sk8
class NinaDeRingsOpponent: public BaseOpponent{
public:
    NinaDeRingsOpponent(){}
    OpponentType Type();
    void updateKnight(BaseKnight *knight);
};
//sk9
class DurianGardenOpponent: public BaseOpponent{
public:
    DurianGardenOpponent(){}
    OpponentType Type();
    void updateKnight(BaseKnight *knight);
};
//sk10
class OmegaWeaponOpponent: public BaseOpponent{
public:
    OmegaWeaponOpponent(){}
    OpponentType Type();
    void updateKnight(BaseKnight *knight);
};
//sk11
class HadesOpponent: public BaseOpponent{
public:
    HadesOpponent(){}
    OpponentType Type();
    void updateKnight(BaseKnight *knight);
};
enum KnightType { PALADIN = 0, LANCELOT, DRAGON, NORMAL };
class BaseKnight {
protected:
    int id;
    int hp;
    int maxhp;
    int level;
    int gil;
    int antidote;
    BaseBag * bag;
    KnightType knightType;
    bool isPoisoned = 0; 
    int residualGil = 0; 
public:
    BaseKnight(){}
    BaseBag* getBag(){
        return this->bag;
    }
    int getid() const { return id; }
    void setid(int id) {
        this->id=id;
    }

    int gethp() const { return hp; }
    void sethp(int hp){
        this->hp = hp > this->maxhp ? this->maxhp : hp;
        this->hp=hp <=0 ? 0 : hp;
    }
    int getmaxhp() const {return this->maxhp;}
    void setmaxhp(int maxhp)  {this->maxhp=maxhp;}
    
    int getlevel() const { return level; }
    void setlevel(int level){
        this->level = level > 10 ? 10 : level;
    }

    int getphoenix() const { return phoenixdownI; }

    int getgil()  { return gil;}
    void setgil(int gil){
        if(gil>999){
            this->residualGil = gil-999;
            this->gil = 999;
        }
        else this->gil = gil < 0 ? 0 : gil;
    }
    
    int getantidote() const { return isPoisoned;}
    void setantidote(int isPoisoned){
        this->isPoisoned = isPoisoned;
    }

    bool setBag(BaseItem *item);

    int getResidualGil(){
        int temp = this->residualGil;
        this->residualGil=0;
        return temp;
        }
    KnightType getType(){
        return this->knightType;
    }
    ~BaseKnight(){
        delete bag;
    }
    static BaseKnight * create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
    virtual bool fight(BaseOpponent *opponent);
    virtual int BaseDamage() = 0;   
    string toString() const;
};
class ArmyKnights {
public:
    BaseKnight** knight;
    int size;

    ArmyKnights (const string & file_armyknights);
    ~ArmyKnights(){
        for(int i;i<size; i++){
            delete[] knight[i];
        }
        delete[] knight;
    };
    bool fight(BaseOpponent *opponent);
    bool adventure (Events *events);
    int count() const;
    BaseKnight * lastKnight() const;
    bool PaladinShield=0;
    bool LancelotSpear=0;
    bool GuinevereHair=0;
    bool ExcaliburSword=0;
    bool hasPaladinShield() const;
    bool hasLancelotSpear() const;
    bool hasGuinevereHair() const;
    bool hasExcaliburSword() const;

    void printInfo() const;
    void printResult(bool win) const;
};
// class Paladinknight
class PaladinKnight : public BaseKnight
{
public:
    PaladinKnight(){
        this->knightType = PALADIN;
    }
    bool fight(BaseOpponent *opponent);
    int BaseDamage(){
        return 0.06 * this->hp * this->level;
    }
};
// class LanceLotKnight
class LancelotKnight : public BaseKnight
{
public:
    int BaseDamage(){
        return 0.05 * this->hp * this->level;
    }
    bool fight(BaseOpponent *opponent);
};
// class DraginKnight
class DragonKnight : public BaseKnight
{
public:
    int BaseDamage(){
        return 0.075 * this->hp * this->level;
    }
    bool fight(BaseOpponent *opponent);
};
// class NormalKnight
class NormalKnight : public BaseKnight
{
public:
    int BaseDamage(){
        return 0;
    }
    bool fight(BaseOpponent *opponent);
};
class BaseItem {
public:
BaseItem *next = NULL;
ItemType item;
    virtual bool canUse ( BaseKnight * knight ) = 0;
    virtual void use ( BaseKnight * knight ) = 0;
};
class Antidote : public BaseItem{
    public:
    Antidote(){ this->item = antidote;}
    bool canUse(BaseKnight * knight);
    void use (BaseKnight * knight);
    ItemType Type ();

};
class PhoenixDownI : public BaseItem{
    public:
    PhoenixDownI(){ this->item = phoenixdownI;}
    bool canUse(BaseKnight * knight);
    void use (BaseKnight * knight);
    ItemType Type ();

};
class PhoenixDownII : public BaseItem{
    public:
    PhoenixDownII(){ this->item = phoenixdownII;}
    bool canUse(BaseKnight * knight);
    void use (BaseKnight * knight);
    ItemType Type ();

};
class PhoenixDownIII : public BaseItem{
    public:
    PhoenixDownIII(){ this->item = phoenixdownIII;}
    bool canUse(BaseKnight * knight);
    void use (BaseKnight * knight);
    ItemType Type ();

};
class PhoenixDownIV : public BaseItem{
    public:
    PhoenixDownIV(){  this->item = phoenixdownIV;}
    bool canUse(BaseKnight * knight);
    void use (BaseKnight * knight);
    ItemType Type ();

};
class Events {
private:
    int* event;
    int size;
public:
    Events(string);
    int count() const;
    int get(int i) const;
    ~Events();
};

class KnightAdventure {
private:
    ArmyKnights * armyKnights;
    Events * events;

public:
    KnightAdventure();
    ~KnightAdventure(){
        delete armyKnights;
        delete events;
    } // TODO:

    void loadArmyKnights(const string & file_ArmyKnight){
        armyKnights = new ArmyKnights(file_ArmyKnight);
    };
    void loadEvents(const string & file_events){
        events = new Events( file_events);
    };
    void run(){
        BaseOpponent::toOmegaWeapon = false;
        BaseOpponent::toHades = false;
        armyKnights->printResult(armyKnights->adventure(events));
    };
};

#endif // __KNIGHT2_H__