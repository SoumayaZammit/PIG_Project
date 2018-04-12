import QtQuick 2.5
import QtQuick.Controls 1.2
import QtQuick.Controls 1.4
import Qt.labs.calendar 1.0




ApplicationWindow {
    id: childWindow
    title: "My ChildWindow"
    width: 640
    height: 480

    property alias text1: text1
    property alias rectangle: rectangleChild
    visible: true
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
        color: "#fefcdc"
        anchors.rightMargin: 0
        anchors.bottomMargin: 24
        anchors.leftMargin: 0
        anchors.topMargin: -24
        anchors.fill: parent
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
            x: 435
            y: 117
            text: qsTr("C'est au Player1 de jouer")
            font.pixelSize: 17
        }



            Text {
                id: text1
                x: 456
                y: 312
                width: 169
                height: 34
                text: qsTr("Instruction Jeu")
                font.pixelSize: 12
            }

            MouseArea {
                id: mouseArea9
                x: -4
                y: 212
                width: 57
                height: 57
            }

            MouseArea {
                id: mouseArea1
                x: 386
                y: 214
                width: 67
                height: 57
            }

            MouseArea {
                id: mouseArea2
                x: 186
                y: 213
                width: 67
                height: 57
            }

            MouseArea {
                id: mouseArea3
                x: 381
                y: 10
                width: 67
                height: 57
            }

            MouseArea {
                id: mouseArea4
                x: 188
                y: 9
                width: 67
                height: 57
            }

            MouseArea {
                id: mouseArea5
                x: -10
                y: 10
                width: 67
                height: 57
            }

            MouseArea {
                id: mouseArea6
                x: 380
                y: 405
                width: 67
                height: 57
            }

            MouseArea {
                id: mouseArea7
                x: 188
                y: 406
                width: 67
                height: 57
            }

            MouseArea {
                id: mouseArea8
                x: -12
                y: 404
                width: 67
                height: 57
            }

            Rectangle {
                id: token1
                x: 1
                y: 16
                width: 45
                height: 43
                color: "#ffffff"
            }

            Rectangle {
                id: token2
                x: 391
                y: 412
                width: 45
                height: 43
                color: "#ffffff"
            }

            Rectangle {
                id: token3
                x: 198
                y: 412
                width: 45
                height: 43
                color: "#ffffff"
            }

            Rectangle {
                id: token4
                x: 1
                y: 412
                width: 45
                height: 43
                color: "#ffffff"
            }

            Rectangle {
                id: token5
                x: 396
                y: 219
                width: 45
                height: 43
                color: "#ffffff"
            }

            Rectangle {
                id: token6
                x: 391
                y: 16
                width: 45
                height: 43
                color: "#ffffff"
            }

            Rectangle {
                id: token7
                x: 198
                y: 16
                width: 45
                height: 43
                color: "#ffffff"
            }

            Rectangle {
                id: token8
                x: 198
                y: 219
                width: 45
                height: 43
                color: "#ffffff"
            }

            Rectangle {
                id: token9
                x: 1
                y: 219
                width: 45
                height: 43
                color: "#ffffff"
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

                MouseArea {
                    anchors.fill: parent
                    onClicked:
                        if(theModel.get(numberDelegate).color == "#ffffff"){
                            if(roundCount%2 == 1){
                                theModel.setProperty(numberDelegate, "color", color=colorPlayer1)
                            }
                            else{
                                theModel.setProperty(numberDelegate, "color", color=colorPlayer2)
                            }
                        }

                }
                states: State {
                        name: "moved"; when: mouseArea.pressed
                        PropertyChanges { target: rect; x: 50; y: 50 }
                    }

                    transitions: Transition {
                        NumberAnimation { properties: "x,y"; easing.type: Easing.InOutQuad }
                    }
            }
        }




    }


