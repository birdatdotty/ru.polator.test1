import QtQuick 2.0
import QtQuick.Controls 2.12

import My 1.0

Item {
    id: main
    property string text: ""
    property bool readOnly: false
    property QmlUser user: qmlUser1

    anchors.fill: parent

    Flickable {
        id: flickable
        property string text: ""
        property bool readOnly: false

        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 40

        TextArea.flickable: TextArea {
            id: ta
            readOnly: flickable.readOnly

            Behavior on x { SmoothedAnimation { velocity: 200 } }
            Behavior on y { SmoothedAnimation { velocity: 200 } }

            Connections {
                target: user
                function onLogChanged() {
                  flickable.contentY =
                          ta.contentHeight < main.height - ti.height
                          ? 0
                          : ta.contentHeight - (main.height - ti.height) + ta.font.pointSize
                }
            }

            anchors.fill: parent
            text: user.log

            wrapMode: Text.Wrap
            font.bold: true
            font.pointSize: 16
        }
        ScrollBar.vertical: ScrollBar { }
    }
    Rectangle {
        id: ti
        color: "#a0eba0"

        height: 40
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        TextInput {
            id: myInput
            text: main.user.status

            anchors.fill: parent
            Keys.onReleased: {
                if (event.key === Qt.Key_Return) {
                    main.user.enter(myInput.text)
                }
            }
        }
    }
}
