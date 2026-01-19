/*********************************************************************
 * @file  Apllication.h
 * @author <Wissal GUARNI Florian GOYHENEIX>
 * @brief Fichier header de l'application
 *********************************************************************/
#ifndef APPLICATION_H_
#define APPLICATION_H_

/**
  * @class Application
  * @brief Classe Application 
*/    
class Application
{
  public :
    /**
     * @fn Application();
     * @brief Constructeur par defaut
    */    
    Application();
    /**
     * @fn Application();
     * @brief Destructeur
    */    
    ~Application();    
    /**
     * @fn void init(void)
     * @brief Fonction d'initialisation de l'application
    */
    void init(void);
    /**
     * @fn void run(void)
     * @brief Fonction de lancement de l'application
    */
    void run(void);
    private:
    // Hardware
    GameHardware hw;
    GameSelector selector;
    ContinueSelector continueSelector;
    ScoreManager scoreManager;
  
};
#endif