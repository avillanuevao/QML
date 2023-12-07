import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 400
    height: 500
    title: "Seleccionar Fondo o Gasto"

//    property int amount: 0
//    property int selectedType: 0
//    property int selectedBucket: 0
//    property int balanceMoney: 0

//    Column {
//        anchors.centerIn: parent
//        spacing: 10

//        ComboBox {
//            id: comboBox01
//            width: 200
//            model: ListModel {
//                ListElement { text: "Fund" }
//                ListElement { text: "Expense" }
//            }
//            currentIndex: 0 // Índice del elemento seleccionado por defecto

//            // Manejar el evento cuando se selecciona un elemento
//            onCurrentIndexChanged: {
//                console.log("Selected:", comboBox01.currentText)
//                selectedType = comboBox01.currentIndex;
//            }
//        }

//        ComboBox {
//            id: comboBox02
//            width: 200
//            model: ListModel {
//                ListElement { text: "Savings" }
//                ListElement { text: "Housing" }
//                ListElement { text: "Food" }
//                ListElement { text: "Transportation" }
//                ListElement { text: "Entertainment" }
//                ListElement { text: "Travel" }
//                ListElement { text: "Clothing" }
//                ListElement { text: "Debts" }
//                ListElement { text: "Car" }
//            }
//            currentIndex: 0 // Índice del elemento seleccionado por defecto

//            // Manejar el evento cuando se selecciona un elemento
//            onCurrentIndexChanged: {
//                console.log("Selected:", comboBox02.currentText)
//                selectedBucket = comboBox02.currentIndex;
//            }
//        }

//        // Entrada para el número entero
//        TextField {
//            placeholderText: "Ingrese un número entero"
//            validator: IntValidator {} // Asegura que solo se ingresen números enteros
//            onTextChanged: {
//                amount = parseInt(text);
//            }
//        }

//        Row
//        {
//            Button {
//                text: "Accept"
//                onClicked: {
//                    // Verificar que appController esté definido antes de usarlo
//                    if (appController) {
//                        // Puedes realizar acciones adicionales según la selección y el número ingresado
//                        if(selectedType == 0) {
//                            //fund
//                            appController.setFund(selectedBucket, amount);
//                        } else {
//                            //expense
//                            appController.setExpense(selectedBucket, amount);
//                        }
//                        balanceMoney = appController.getMoneyBalance(selectedBucket);
//                    } else {
//                        console.error("appController is not defined");
//                    }
//                }
//            }

//            Text {
//                id: textBalance
//                text: balanceMoney
//            }
//        }

//        Button {
//            text: "Reset"
//            onClicked: {
//                appController.resetBucketType(selectedBucket);
//                balanceMoney = appController.getMoneyBalance(selectedBucket);
//            }
//        }



//    }

//    function getBucketType(name) {
//        var bucketTypeMap = {
//            "Savings": 0,
//            "Housing": 1,
//            "Food": 2,
//            "Transportation": 3,
//            "Entertainment": 4,
//            "Travel": 5,
//            "Clothing": 6,
//            "Debts": 7,
//            "Car": 8
//            // Agrega otros elementos según sea necesario
//        };

//        // Devuelve el valor numérico asociado al nombre o -1 si no se encuentra
//        return bucketTypeMap.hasOwnProperty(name) ? bucketTypeMap[name] : -1;
//    }

//    function updateView() {
//        // Reinicia el modelo del Repeater
//        repeater.model = repeater.model;
//        console.log("Updating view...");
//    }
}
