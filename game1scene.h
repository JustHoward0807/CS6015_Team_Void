#ifndef GAME1SCENE_H
#define GAME1SCENE_H

#include <QAudioOutput>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QObject>
#include <QWidget>

#include "firebasedbhelper.h"
#include <QtWidgets>
#include <QMediaPlayer>
#include <QAudioOutput>
#include "bucket.h"
#include "user.h"
#include <QtMultimedia/QMediaPlayer>
#include <QAudioOutput>
#include <QDateTime>
#include <vector>
#include <sstream>

class game1scene : public QGraphicsScene
{
    Q_OBJECT
    QGraphicsTextItem *scoreText;
    QGraphicsTextItem *hpText;
    int actualScore;

    QMediaPlayer *musicPlayer;
    QAudioOutput *audioOutput;
    QDateTime *currentDate = new QDateTime;

    int *health_count;
    int *droplet_count;

    QLabel *birthday;
    bool isBirthday;
    QLabel *user_name;
    QPushButton *button_profile;
    QPushButton *button_score_board;
    QPushButton *button_signout;
    QHBoxLayout *userHLayout;
    QGroupBox *userBox;
    QGraphicsProxyWidget * userSection;


    bucket *bucketItem;
    QLabel *level;
    QVBoxLayout *levelVLayout;
    QPushButton *button_easy;
    QPushButton *button_medium;
    QPushButton *button_hard;
    QGroupBox *levelBox;
    QGraphicsProxyWidget * levelSection;
    int hardness_born;
    int hardness_rate;

    QLabel *over;
    QLabel *score;
    QPushButton *button_restart;
    QPushButton *button_close;
    QVBoxLayout *overVLayout;
    QHBoxLayout *overHLayout;
    QGroupBox *overBox;
    QGraphicsProxyWidget *overSection;

    QTimer *dropletGeneration;

    //Firebase stuff
    User *user = new User;
    FirebaseDBHelper dbHelper;

    QMediaPlayer *music;
    QAudioOutput *audioOut;

public:
    game1scene(User *user);
    void playGame(int time);
    void gameOver(int s);
    void start();
    void setUser(User *user);



signals:
    void end();


public slots:
    void addingDroplet();
    void mode_easy();
    void mode_medium();
    void mode_hard();
    void restart();
    void openProfile();
    void openRank();
    void signOut();
    void close();
};

#endif // GAME1SCENE_H
