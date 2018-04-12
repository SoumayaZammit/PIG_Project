import QtQuick 2.3
import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 1.2
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Dialogs 1.0



Window {
    id: root
    visible: true
    width: 750
    height: 480
    maximumHeight: 480
    minimumHeight: 480
    maximumWidth: 750
    minimumWidth: 750
    property alias text_Language: text_Language
    property alias colorDialogP1: colorDialogP1
    property alias colorDialogP2: colorDialogP2
    title: qsTr("Game Settings") +vueGame.emptyString

    ColorDialog {
        id: colorDialogP1
        title: "Choose your color"
        onAccepted: {
            vueGame.setPlayerColor(1, colorDialogP1.color)
            console.log(colorDialogP1.color)
            this.close()
        }
        onRejected: {
            console.log("Cancelled")
            Qt.quit()
        }
        Component.onCompleted: visible = false
    }
    ColorDialog {
        id: colorDialogP2
        title: "Choose your color"
        onAccepted: {
            vueGame.setPlayerColor(2, colorDialogP2.color)
            console.log(colorDialogP2.color)
            this.close()
        }
        onRejected: {
            console.log("Cancelled")
            Qt.quit()
        }
        Component.onCompleted: visible = false
    }


    Rectangle {
        id: rectangle8
        x: 0
        y: 0
        width: 750
        height: 480
        color: "#fefcdc"
        border.width: 0
        gradient: Gradient {
            GradientStop {
                position: 0
                color: "#fefcdc"
            }

            GradientStop {
                position: 1
                color: "#aaa54c"
            }
        }

        Image {
            id: image
            x: 8
            y: 158
            width: 300
            fillMode: Image.PreserveAspectFit
            source: "spider.png"
        }

        Text {
            id: text_Language
            x: 363
            y: 160
            height: 25
            text: qsTr("Language")
            style: Text.Normal
            font.family: "Verdana"
            font.weight: Font.Black
            font.capitalization: Font.MixedCase
            font.bold: true
            font.pixelSize: 14
            fontSizeMode: Text.VerticalFit
            textFormat: Text.AutoText
            verticalAlignment: Text.AlignVCenter
            elide: Text.ElideNone
            wrapMode: Text.NoWrap
        }

        Text {
            id: text_Player1
            x: 363
            y: 230
            width: 53
            height: 25
            text: qsTr("Player1")
            verticalAlignment: Text.AlignVCenter
            font.bold: true
            font.weight: Font.Black
            font.pixelSize: 14
        }

        Text {
            id: text_Player2
            x: 364
            y: 272
            height: 25
            text: qsTr("Player2")
            verticalAlignment: Text.AlignVCenter
            font.weight: Font.Black
            font.bold: true
            font.pixelSize: 14
        }

        Button {
            id: button_start
            x: 434
            y: 385
            width: 102
            height: 42
            text: qsTr("Start")
            activeFocusOnPress: true
            isDefault: false
            onClicked: {
                childWindow.visible = !childWindow.visible
                root.visible = !root.visible

            }
        }

        Text {
            id: text_titre
            x: 213
            y: 65
            text: qsTr("Jeu d'araignée")
            anchors.horizontalCenter: parent.horizontalCenter
            font.pixelSize: 34
        }

        Button {
            id: button
            x: 505
            y: 230
            width: 130
            height: 23
            text: qsTr("Color P1")
            activeFocusOnPress: true
            onClicked:{
                colorDialogP1.open();
            }
        }

        Button {
            id: button1
            x: 505
            y: 274
            width: 130
            height: 23
            text: qsTr("Color P2")
            activeFocusOnPress: true
            onClicked:{
                colorDialogP2.open();
            }
        }

        Button {
            id: button2
            x: 479
            y: 160
            width: 75
            height: 25
            text: qsTr("English")
            onClicked :vueGame.language(0)
        }

        Button {
            id: button3
            x: 573
            y: 160
            width: 75
            height: 26
            text: qsTr("Français")
            onClicked :vueGame.language(1)
        }
    }

    ApplicationWindow {
        id: childWindow
        title: "Game"
        width: 750
        height: 480
        maximumHeight: 480
        minimumHeight: 480
        maximumWidth: 750
        minimumWidth: 750
        property alias rectangle: rectangleChild
        visible: false
        property alias text1: text1
        property alias mouseArea8: mouseArea8
        property alias mouseArea7: mouseArea7
        property alias mouseArea6: mouseArea6
        property alias mouseArea5: mouseArea5
        property alias mouseArea3: mouseArea3
        property alias mouseArea4: mouseArea4
        property alias mouseArea1: mouseArea1
        property alias mouseArea2: mouseArea2
        property alias mouseArea9: mouseArea9
        Rectangle {
            id: rectangleChild
            width: 750
            height: 480
            gradient: Gradient {
                GradientStop {
                    position: 0
                    color: "#fefcdc"
                }

                GradientStop {
                    position: 1
                    color: "#aaa54c"
                }
            }
            visible: true




            Image {
                id: image_cobweb
                x: -30
                y: 26
                width: 500
                height: 429
                fillMode: Image.PreserveAspectFit
                source: "cobweb.png"
            }

            Text {
                id: text_message
                x: 475
                y: 117
                text: vueGame.currentText
                font.pixelSize: 18
                color: "#568203"
                wrapMode: Text.WordWrap
                width: rectangleChild.width
            }



            Text {
                id: text1
                x: 475
                y: 217
                text: vueGame.currentInstructions
                font.pixelSize: 15
                color: "#A91101"
                wrapMode: Text.WordWrap
                width: rectangleChild.width

            }

            MouseArea {
                id: mouseArea9
                x: -4
                y: 212
                width: 57
                height: 57
                onClicked: vueGame.play(8);
            }

            MouseArea {
                id: mouseArea1
                x: 386
                y: 214
                width: 67
                height: 57
                onClicked: vueGame.play(4);
            }

            MouseArea {
                id: mouseArea2
                x: 186
                y: 213
                width: 67
                height: 57
                onClicked: vueGame.play(7);
            }

            MouseArea {
                id: mouseArea3
                x: 381
                y: 10
                width: 67
                height: 57
                onClicked: vueGame.play(5);
            }

            MouseArea {
                id: mouseArea4
                x: 188
                y: 9
                width: 67
                height: 57
                onClicked: vueGame.play(6);
            }

            MouseArea {
                id: mouseArea5
                x: -10
                y: 10
                width: 67
                height: 57
                onClicked: vueGame.play(0);
            }

            MouseArea {
                id: mouseArea6
                x: 380
                y: 405
                width: 67
                height: 57
                onClicked: vueGame.play(1);
            }

            MouseArea {
                id: mouseArea7
                x: 188
                y: 406
                width: 67
                height: 57
                onClicked: vueGame.play(2);
            }

            MouseArea {
                id: mouseArea8
                x: -12
                y: 404
                width: 67
                height: 57
                onClicked: vueGame.play(3);
            }

            Rectangle {
                id: token1
                x: 1
                y: 16
                width: 45
                height: 43
                color: vueGame.gameQML[0]
            }

            Rectangle {
                id: token2
                x: 391
                y: 412
                width: 45
                height: 43
                color: vueGame.gameQML[1]
            }

            Rectangle {
                id: token3
                x: 198
                y: 412
                width: 45
                height: 43
                color: vueGame.gameQML[2]
            }

            Rectangle {
                id: token4
                x: 1
                y: 412
                width: 45
                height: 43
                color: vueGame.gameQML[3]
            }

            Rectangle {
                id: token5
                x: 396
                y: 219
                width: 45
                height: 43
                color: vueGame.gameQML[4]
            }

            Rectangle {
                id: token6
                x: 391
                y: 16
                width: 45
                height: 43
                color: vueGame.gameQML[5]
            }

            Rectangle {
                id: token7
                x: 198
                y: 16
                width: 45
                height: 43
                color: vueGame.gameQML[6]
            }

            Rectangle {
                id: token8
                x: 198
                y: 219
                width: 45
                height: 43
                color: vueGame.gameQML[7]
            }

            Rectangle {
                id: token9
                x: 1
                y: 219
                width: 45
                height: 43
                color: vueGame.gameQML[8]
            }

        }

        Component {
            id: numberDelegate


            Rectangle {
                id: wrapper

                width: 40
                height: 40
                //color: "#ffffff"
                border.color: "#000000"
                border.width: 3
            }
        }
    }

}




