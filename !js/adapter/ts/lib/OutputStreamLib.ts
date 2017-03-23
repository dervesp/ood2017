export interface IOutputStream {
    print(message: string);
}

export class CConsoleOutputStream implements IOutputStream {
    print(message: string) {
        console.log(message);
    }
}

const ELEMENT_WRAPPER_ID: string = "htmlOutputConsoleWrapper";
const ELEMENT_ID: string = "htmlOutputConsole";

export class CHtmlOutputStream implements IOutputStream {
    private m_wrapperEl: Element;
    private m_consoleEl: Element;

    constructor() {
        let wrapperEl = document.getElementById(ELEMENT_WRAPPER_ID);
        if (!wrapperEl) {
            wrapperEl = document.createElement("div");
            wrapperEl.setAttribute("id", ELEMENT_WRAPPER_ID);
            wrapperEl.setAttribute("style", "position:fixed; width:100%; height:100%; top:0; left:0; overflow-y: scroll;");
            document.body.appendChild(wrapperEl);
        }
        this.m_wrapperEl = wrapperEl;
        let consoleEl = document.getElementById(ELEMENT_ID);

        if (!consoleEl) {
            consoleEl = document.createElement("pre");
            consoleEl.setAttribute("id", ELEMENT_ID);
            consoleEl.setAttribute("style", "background:black; color:lightgray; font-size:18px; min-height:100%; margin:0;");

            wrapperEl.appendChild(consoleEl);
        }
        this.m_consoleEl = consoleEl;
    }

    print(message: string) {
        this.m_consoleEl.appendChild(document.createTextNode(message));
        this.m_wrapperEl.scrollTop = this.m_wrapperEl.scrollHeight;
    }
}