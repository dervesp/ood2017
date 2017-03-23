import {IOutputStream} from "./OutputStreamLib";
export interface ICanvas {
    begin();
    moveTo(x: number, y: number);
    lineTo(x: number, y: number);
    end();
}

export class CCanvas implements ICanvas {
    private m_out: IOutputStream;

    constructor(outputStream: IOutputStream) {
        this.m_out = outputStream;
    }

    begin() {}

    end() {}

    moveTo(x: number, y: number) {
        this.m_out.print(`moveTo (${x}, ${y})\n`);
    }

    lineTo(x: number, y: number) {
        this.m_out.print(`lineTo (${x}, ${y})\n`);
    }
}