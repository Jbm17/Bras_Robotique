# Bras_Robotique

## ✅ Avant d'exécuter ce programme, assurez-vous que vous avez installé les éléments suivants :

### **1. Android Studio**

Téléchargez et installez **[Android Studio](https://developer.android.com/studio?hl=fr)**, qui vous permettra de développer et de lancer l'application Android.

---

### **2. Fonctionnalités de l’application Android :**

Cette application permet de **contrôler un bras robotique** à distance en envoyant des commandes via **TCP/IP** à un PC. Vous pouvez effectuer divers mouvements du bras, de la pince, etc., directement depuis l'application.

---

### **3. Commandes :**

| **Action**                         | **Touche** |
|-------------------------------------|------------|
| Épaule ↓                          | E          |
| Épaule ↑                          | e          |
| Base ←                            | B          |
| Base →                            | b          |
| Coude ↑                           | C          |
| Coude ↓                           | c          |
| Pince ← (Rotation gauche)         | r          |
| Pince → (Rotation droite)         | R          |
| Robot réinitialisé                | I          |
| Arrêt de la machine               | S          |
| Pince fermée                      | o          |
| Pince ouverte                     | O          |
| Poignet Haut                      | m          |
| Poignet Bas                       | M          |

---

### **4. Configuration de l'application :**

#### ⚙️ **Configuration de l'application**

##### 1. Configurer votre environnement Android Studio

- Téléchargez et installez **[Android Studio](https://developer.android.com/studio)**.
- Ouvrez le projet dans Android Studio.

##### 2. Lancer l'application

- Exécutez l'application sur votre appareil Android ou un émulateur.
- L'application sera prête à envoyer des commandes une fois lancée.

##### 3. Connecter à un réseau local

- Assurez-vous que votre smartphone est connecté à un réseau **Wi-Fi local**.

##### 4. Utilisation de l'interface

- L'application propose des boutons pour envoyer des commandes.
- En appuyant sur les touches, les commandes sont envoyées au **PC via TCP/IP**.

---

### **5. OBJECTIF**

Cette application Android permet d'envoyer des commandes au **PC**, qui les transmet ensuite au robot via une connexion **USB**. Elle offre une interface de contrôle du robot et permet également de visualiser en direct les mouvements grâce à la caméra.

---

### Remarques supplémentaires :

- Cette application ne gère pas directement la communication avec l'Arduino, elle se contente d'envoyer des commandes via TCP/IP.
- Assurez-vous que le **PC** qui reçoit les commandes est configuré pour traiter et transmettre ces commandes à l'Arduino.
