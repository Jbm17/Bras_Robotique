# Bras_Robotique

**Avant d'exécuter ce programme, assurez-vous que vous avez installé les éléments suivants :**

1.**Arduino**

*Voici le liens qui permettra d'installer l'application Arduino.*

https://www.arduino.cc/en/software/

**Commandes :**
```
    switch (command) {
      case 'b': sens_rotation(HIGH); moteur_mov(300, BASE); break;
      case 'B': sens_rotation(LOW);  moteur_mov(300, BASE); break;
      case 'e': sens_rotation(HIGH); moteur_mov(300, EPAULE_BAS); break;
      case 'E': sens_rotation(LOW);  moteur_mov(300, EPAULE_HAUT); break;
      case 'c': sens_rotation(HIGH); moteur_mov(300, COUDE_HAUT); break;
      case 'C': sens_rotation(LOW);  moteur_mov(300, COUDE_BAS); break;
      case 'm': sens_rotation(LOW);  moteur_mov(300, POIGNET_HAUT); break;
      case 'M': sens_rotation(HIGH); moteur_mov(300, POIGNET_BAS); break;
      case 'r': sens_rotation(HIGH); moteur_mov(300, ROTATION_POIGNET_GAUCHE); break;
      case 'R': sens_rotation(LOW);  moteur_mov(300, ROTATION_POIGNET_DROITE); break;
      case 'o': sens_rotation(HIGH); moteur_mov(300, PINCE_FERMER); break;
      case 'O': sens_rotation(LOW);  moteur_mov(300, PINCE_OUVERT); break;      case '1':
        position_initiale();
        sens_rotation(LOW);  moteur_mov(1000, BASE);
        sens_rotation(HIGH); moteur_mov(2000, BASE);
        break;
      case 'I':
        position_initiale(); break;
    }
```
**Fonctionnalités :**

  `` Ce programme en C++ utilise Arduino qui permet de manipuler le robot Youpi du projet.``
  
   ``Il vas ensuite traduire les commandes reçu et les éxécuter en temps réel.``

   
# Résultat attendu : 

 [Capture vidéo du 2025-04-29 10-41-02.webm](https://github.com/user-attachments/assets/bbc1948a-a235-4c58-afcb-93c82bb5114f)
    
