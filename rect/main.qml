import QtQuick 2.10
import QtQuick.Window 2.10
import QtCharts 2.2
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.2

Window {

    function close(){
        Qt.quit();
    }
    id: mainWindow
    visible: true
    width: 1024
    height: 500
    color: "#148e9d"
    screen: none.none
    visibility: none.none
    title: "Mailer"

    ColumnLayout{


        Label{
            text: qsTr("From")
            x: 200
        }
        Button{
            id: control
            text: "Send"
            x:400
            y:400
            onClicked:{
                mainWindow.close();



            }
            contentItem: Text {
                    text: "Send"
                    opacity: enabled ? 1.0 : 0.3
                    color:Control.down ? "blue" : "#21be2b"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    elide: Text.ElideRight
                }

                background: Rectangle {
                    implicitWidth: 100
                    implicitHeight: 40
                    opacity: enabled ? 1 : 0.3
                    border.color: control.down ? "#17a81a" : "#21be2b"
                    border.width: 1
                    radius: 2
                }
        }
    }




}

