import QtQuick 2.3
import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 1.2
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4



Window {
    id: root
    visible: true
    width: 640
    height: 480
    property alias comboBox_Language: comboBox_Language
    property alias text_Language: text_Language
    title: qsTr("Hello World")



    Rectangle {
        id: rectangle8
        width: 640
        height: 480
        color: "#fefcdc"
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
            x: 320
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

        ComboBox {
            id: comboBox_Language
            x: 420
            y: 160
            width: 130
            height: 25
            model: ["English", "Français"]
        }

        Text {
            id: text_Player1
            x: 320
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
            x: 320
            y: 270
            height: 25
            text: qsTr("Player2")
            verticalAlignment: Text.AlignVCenter
            font.weight: Font.Black
            font.bold: true
            font.pixelSize: 14
        }

        Button {
            id: button
            x: 420
            y: 230
            width: 25
            height: 25
            opacity: 0.6
            style: ButtonStyle {
                background: Rectangle {
                    color: "#888"
                }
            }

            Rectangle {
                id: rectangle
                color: "#07ef07"
                anchors.fill: parent

                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        if(colorPlayer2 != "#07ef07"){
                            parent.border.color = "#000000"
                            parent.border.width = 2
                            rectangle1.border.color = "#00000000"
                            rectangle2.border.color = "#00000000"
                            rectangle3.border.color = "#00000000"
                            colorPlayer1 = "#07ef07"
                        }
                    }
                }
            }
        }

        Button {
            id: button1
            x: 455
            y: 230
            width: 25
            height: 25

            opacity: 0.6
            style: ButtonStyle {
                background: Rectangle {
                    color: "#888888"
                }
            }

            Rectangle {
                id: rectangle1
                color: "#011195"
                anchors.fill: parent

                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        if(colorPlayer2 != "#011195"){
                            parent.border.color = "#000000"
                            parent.border.width = 2
                            rectangle.border.color = "#00000000"
                            rectangle2.border.color = "#00000000"
                            rectangle3.border.color = "#00000000"
                            colorPlayer1 = "#011195"
                        }
                    }
                }
            }
        }

        Button {
            id: button2
            x: 490
            y: 230
            width: 25
            height: 25
            Rectangle {
                id: rectangle2
                color: "#f40202"
                anchors.fill: parent

                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        if(colorPlayer2 != "#f40202"){
                            parent.border.color = "#000000"
                            parent.border.width = 2
                            rectangle.border.color = "#00000000"
                            rectangle1.border.color = "#00000000"
                            rectangle3.border.color = "#00000000"
                            colorPlayer1 = "#f40202"
                        }
                    }
                }
            }
            opacity: 0.6
            style: ButtonStyle {
                background: Rectangle {
                    color: "#888888"
                }
            }
        }

        Button {
            id: button3
            x: 525
            y: 230
            width: 25
            height: 25
            Rectangle {
                id: rectangle3
                color: "#fdfd06"
                anchors.fill: parent

                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        if(colorPlayer2 != "#fdfd06"){
                            parent.border.color = "#000000"
                            parent.border.width = 2
                            rectangle.border.color = "#00000000"
                            rectangle1.border.color = "#00000000"
                            rectangle2.border.color = "#00000000"
                            colorPlayer1 = "#fdfd06"
                        }
                    }
                }
            }
            opacity: 0.6
            style: ButtonStyle {
                background: Rectangle {
                    color: "#888888"
                }
            }
        }

        Button {
            id: button4
            x: 420
            y: 270
            width: 25
            height: 25
            Rectangle {
                id: rectangle4
                color: "#07ef07"
                anchors.fill: parent

                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        if(colorPlayer1 != "#07ef07"){
                            parent.border.color = "#000000"
                            parent.border.width = 2
                            rectangle5.border.color = "#00000000"
                            rectangle6.border.color = "#00000000"
                            rectangle7.border.color = "#00000000"
                            colorPlayer2 = "#07ef07"
                        }
                    }
                }
            }
            opacity: 0.6
            style: ButtonStyle {
                background: Rectangle {
                    color: "#888888"
                }
            }
        }

        Button {
            id: button5
            x: 455
            y: 270
            width: 25
            height: 25
            Rectangle {
                id: rectangle5
                color: "#011195"
                anchors.fill: parent

                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        if(colorPlayer1 != "#011195"){
                            parent.border.color = "#000000"
                            parent.border.width = 2
                            rectangle4.border.color = "#00000000"
                            rectangle6.border.color = "#00000000"
                            rectangle7.border.color = "#00000000"
                            colorPlayer2 = "#011195"
                        }
                    }
                }
            }
            opacity: 0.6
            style: ButtonStyle {
                background: Rectangle {
                    color: "#888888"
                }
            }
        }

        Button {
            id: button6
            x: 490
            y: 270
            width: 25
            height: 25
            Rectangle {
                id: rectangle6
                color: "#f40202"
                anchors.fill: parent

                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        if(colorPlayer1 != "#f40202"){
                            parent.border.color = "#000000"
                            parent.border.width = 2
                            rectangle4.border.color = "#00000000"
                            rectangle5.border.color = "#00000000"
                            rectangle7.border.color = "#00000000"
                            colorPlayer2 = "#f40202"
                        }
                    }
                }
            }
            opacity: 0.6
            style: ButtonStyle {
                background: Rectangle {
                    color: "#888888"
                }
            }
        }

        Button {
            id: button7
            x: 525
            y: 270
            width: 25
            height: 25
            Rectangle {
                id: rectangle7
                color: "#fdfd06"
                anchors.fill: parent

                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        if(colorPlayer1 != "#fdfd06"){
                            parent.border.color = "#000000"
                            parent.border.width = 2
                            rectangle4.border.color = "#00000000"
                            rectangle5.border.color = "#00000000"
                            rectangle6.border.color = "#00000000"
                            colorPlayer2 = "#fdfd06"
                        }
                    }
                }
            }
            opacity: 0.6
            style: ButtonStyle {
                background: Rectangle {
                    color: "#888888"
                }
            }
        }

        Button {
            id: button_start
            x: 453
            y: 341
            text: qsTr("Start")
            onClicked: {
                /*var component = Qt.createComponent("page_game.qml")
                var window = component.createObjet(childWindow)
                window.show()
                */
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
    }

    ApplicationWindow {
        id: childWindow
        title: "My ChildWindow"
        width: 640
        height: 480
        property alias rectangle: rectangleChild
        visible: false

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

            Text {
                id: text_message
                x: 430
                y: 230
                text: qsTr("C'est au Player1 de jouer")
                font.pixelSize: 17
            }

            Image {
                id: image_cobweb
                x: -30
                y: 26
                width: 500
                height: 429
                fillMode: Image.PreserveAspectFit
                source: "cobweb.png"
            }

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

            GridView {
                anchors.fill: parent
                anchors.margins: 20

                clip: true

                model: theModel

                cellWidth: 180
                cellHeight: 200


                delegate: numberDelegate
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
}

