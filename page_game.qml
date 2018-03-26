import QtQuick 2.5
import QtQuick.Controls 1.2
import QtQuick.Controls 1.4



ApplicationWindow {
    id: childWindow
    title: "My ChildWindow"
    width: 640
    height: 480
    property alias rectangle: rectangle
    visible: true

    Rectangle {
        id: rectangle
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

            ListElement { number: 0 }
            ListElement { number: 1 }
            ListElement { number: 2 }
            ListElement { number: 3 }
            ListElement { number: 4 }
            ListElement { number: 5 }
            ListElement { number: 6 }
            ListElement { number: 7 }
            ListElement { number: 8 }
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
        }

        Component {
            id: numberDelegate

            Rectangle {
                id: wrapper

                width: 40
                height: 40
                color: "#ffffff"
                border.color: "#000000"
                border.width: 3


                MouseArea {
                    anchors.fill: parent

                    onClicked: {
                        theModel.remove(index);
                    }
                }

            }
        }




    }

}
