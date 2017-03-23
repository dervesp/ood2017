import {IOutputStream} from "./OutputStreamLib";

export class CPoint {
    private m_x: number;
    private m_y: number;
    constructor(x: number, y: number) {
        this.m_x = x;
        this.m_y = y;
    }

    x(): number {
        return this.m_x;
    }

    y(): number {
        return this.m_y;
    }
}

export class CModernGraphicsRenderer {
    m_out: IOutputStream;
    m_drawing: boolean;
    constructor(outputStream: IOutputStream) {
        this.m_out = outputStream;
        this.m_drawing = false;
    }

    beginDraw() {
        if (this.m_drawing) {
            throw new Error("Drawing has already begun");
        }
        this.m_out.print(`<draw>\n`);
        this.m_drawing = true;
    }

    drawLine(p1: CPoint, p2: CPoint) {
        if (!this.m_drawing) {
            throw new Error("DrawLine is allowed between BeginDraw()/EndDraw() only");
        }
        this.m_out.print(`<line fromX="${p1.x()}" fromY="${p1.y()}" toX="${p2.x()}" toY="${p2.y()}" />\n`);
    }

    endDraw() {
        if (!this.m_drawing) {
            throw new Error("Drawing has not been started");
        }
        this.m_out.print(`</draw>\n`);
        this.m_drawing = false;
    }
}