// The module 'vscode' contains the VS Code extensibility API
// Import the module and reference it with the alias vscode in your code below
import * as vscode from 'vscode';

// This method is called when your extension is activated
// Your extension is activated the very first time the command is executed
export function activate(context: vscode.ExtensionContext) {
    // Use the console to output diagnostic information (console.log) and errors (console.error)
    // This line of code will only be executed once when your extension is activated
    console.log('Congratulations, your extension "gsql-fmt" is now active!');

    // The command has been defined in the package.json file
    // Now provide the implementation of the command with registerCommand
    // The commandId parameter must match the command field in package.json
    let disposable = vscode.commands.registerCommand('gsql-fmt.gsql-fmt', () => {
        // The code you place here will be executed every time your command is executed
        // Display a message box to the user
        vscode.window.showInformationMessage('Hello World from gsql-fmt!');
    });

    context.subscriptions.push(disposable);

    vscode.languages.registerDocumentFormattingEditProvider('gsql', provider);
    vscode.languages.registerDocumentFormattingEditProvider('plaintext', provider);
}

// This method is called when your extension is deactivated
export function deactivate() {}

const provider: vscode.DocumentFormattingEditProvider = {
    provideDocumentFormattingEdits(document: vscode.TextDocument): vscode.TextEdit[] | null {
        //https://github.com/microsoft/vscode-extension-samples/tree/main/document-editing-sample
        // make the first line the language ID
        const langId = document.languageId;
        const l1 = document.lineAt(0);
        if (l1.text === langId) {
            vscode.window.showInformationMessage(`the languageID: ${langId} is already there`);
            return null;
        }

        return [vscode.TextEdit.insert(document.lineAt(0).range.start, langId + '\n')];
    },
};
