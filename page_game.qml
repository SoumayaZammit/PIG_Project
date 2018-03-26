import QtQuick 2.5
import QtQuick.Controls 1.2
import QtQuick.Controls 1.4



ApplicationWindow {
    id: childWindow
    title: "My ChildWindow"
    width: 640
    height: 480
    property alias rectangle: rectangleChild
    visible: true

    Rectangle {
        id: rectangleChild
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


        /*
        GridView {
            id: view
            anchors.fill: parent
            anchors.margins: 20

            clip: true

            model: 9

            cellWidth: 180
            cellHeight: 200

            delegate: numberDelegate
            //spacing: 5
        }

        Component {
            id: numberDelegate

            Rectangle {
                width: 40
                height: 40
                color: "#179e3d"
                //text: index
            }
        }*/

        Image {
            id: image_cobweb
            x: -30
            y: 26
            width: 500
            height: 429
            fillMode: Image.PreserveAspectFit
            source: "cobweb.png"
        }

        ListModel {
            id: theModel

            ListElement {
                number: 0
                color: "#ffffff"
            }
            ListElement {
                number: 1
                color: "#ffffff"
            }
            ListElement {
                number: 2
                color: "#ffffff"
            }
            ListElement {
                number: 3
                color: "#ffffff"
            }
            ListElement {
                number: 4
                color: "#ffffff"
            }
            ListElement {
                number: 5
                color: "#ffffff"
            }
            ListElement {
                number: 6
                color: "#ffffff"
            }
            ListElement {
                number: 7
                color: "#ffffff"
            }
            ListElement {
                number: 8
                color: "#ffffff"
            }
        }

        Text {
            id: text_message
            x: 425
            y: 230
            text: qsTr("C'est au Player1 de jouer")
            font.pixelSize: 17
        }

        GridView {
            anchors.fill: parent
            anchors.margins: 20

            clip: true

            model: theModel

            cellWidth: 180
            cellHeight: 200


            delegate: numberDelegate

            Text {
                id: text1
                x: 425
                y: 317
                width: 169
                height: 34
                text: qsTr("Instruction Jeu")
                font.pixelSize: 12
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

}
