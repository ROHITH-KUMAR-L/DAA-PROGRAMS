const http = require('http');
const fs = require('fs');
const path = require('path');

const PORT = process.env.PORT || 8080;
const HOST = '0.0.0.0';

// Mapping of route path to file name
const fileMap = {
    '/1': 'merge_sort.c',
    '/2': 'topological_dfs.c',
    '/3': 'heapsort.c',
    '/4': 'horspool.c',
    '/5': 'warshall_floyd.c',
    '/6': 'knapsack_memory.c',
    '/7': 'dijkstra.c',
    '/8': 'prim.c',
    '/9': 'n_queens.c'
};

// Program names for UI dashboard
const programNames = {
    '/1': 'Merge sort with time complexity analysis',
    '/2': 'Topological sorting using Depth First Search (DFS)',
    '/3': 'Heapsort',
    '/4': "Horspool's algorithm",
    '/5': "Warshall & Floyd's algorithms",
    '/6': 'Knapsack problem solution using memory function',
    '/7': "Dijkstra's shortest paths algorithm",
    '/8': "Prim's minimum spanning tree algorithm",
    '/9': "N-Queen's problem (backtracking)"
};

// Generate HTML dashboard dynamically
function getDashboardHtml(reqHost) {
    const hostIp = reqHost || '127.0.0.1:8080';
    let rowsHtml = '';
    
    Object.entries(programNames).forEach(([route, desc]) => {
        const curlCmd = `curl -X POST http://${hostIp}${route} --output ${fileMap[route]}`;
        const routeId = route.replace('/', '');
        rowsHtml += `
        <tr>
            <td class="route-cell">${route}</td>
            <td class="desc-cell">${desc}</td>
            <td class="file-cell"><code>${fileMap[route]}</code></td>
            <td class="cmd-cell">
                <div class="code-wrapper">
                    <code id="cmd-${routeId}">${curlCmd}</code>
                    <button class="copy-btn" onclick="copyToClipboard('cmd-${routeId}')">
                        <svg xmlns="http://www.w3.org/2000/svg" height="16" viewBox="0 -960 960 960" width="16" fill="currentColor"><path d="M360-240q-33 0-56.5-23.5T280-320v-480q0-33 23.5-56.5T360-880h360q33 0 56.5 23.5T800-800v480q0-33-23.5-56.5T720-240H360Zm0-80h360v-480H360v480ZM200-80q-33 0-56.5-23.5T120-160v-560h80v560h440v80H200Zm160-240v-480 480Z"/></svg>
                    </button>
                </div>
            </td>
        </tr>`;
    });

    return `<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>DAA Lab Programs Downloader</title>
    <link href="https://fonts.googleapis.com/css2?family=Outfit:wght@300;400;600;700&family=JetBrains+Mono:wght@400;500&display=swap" rel="stylesheet">
    <style>
        :root {
            --bg-color: #0d1117;
            --card-bg: #161b22;
            --border-color: #30363d;
            --text-main: #c9d1d9;
            --text-muted: #8b949e;
            --primary: #58a6ff;
            --primary-hover: #1f6feb;
            --success: #3fb950;
            --code-bg: #090c10;
        }

        * {
            box-sizing: border-box;
            margin: 0;
            padding: 0;
        }

        body {
            font-family: 'Outfit', sans-serif;
            background-color: var(--bg-color);
            color: var(--text-main);
            line-height: 1.6;
            padding: 2rem 1rem;
        }

        .container {
            max-width: 1100px;
            margin: 0 auto;
        }

        header {
            text-align: center;
            margin-bottom: 3rem;
            padding-bottom: 2rem;
            border-bottom: 1px solid var(--border-color);
        }

        h1 {
            font-size: 2.5rem;
            font-weight: 700;
            color: #ffffff;
            margin-bottom: 0.5rem;
            letter-spacing: -0.5px;
            background: linear-gradient(45deg, #58a6ff, #bc8cff);
            -webkit-background-clip: text;
            -webkit-text-fill-color: transparent;
        }

        p.subtitle {
            font-size: 1.1rem;
            color: var(--text-muted);
        }

        .info-card {
            background-color: var(--card-bg);
            border: 1px solid var(--border-color);
            border-radius: 12px;
            padding: 1.5rem;
            margin-bottom: 2rem;
            box-shadow: 0 4px 12px rgba(0,0,0,0.15);
        }

        .info-card h3 {
            color: #ffffff;
            margin-bottom: 0.75rem;
            font-weight: 600;
        }

        .info-card ul {
            list-style-position: inside;
            color: var(--text-muted);
            margin-left: 0.5rem;
        }

        .info-card li {
            margin-bottom: 0.25rem;
        }

        .info-card code {
            font-family: 'JetBrains Mono', monospace;
            background-color: var(--code-bg);
            padding: 0.2rem 0.4rem;
            border-radius: 4px;
            color: var(--primary);
            font-size: 0.9em;
        }

        .table-container {
            overflow-x: auto;
            border-radius: 12px;
            border: 1px solid var(--border-color);
            background-color: var(--card-bg);
            box-shadow: 0 8px 24px rgba(0,0,0,0.2);
        }

        table {
            width: 100%;
            border-collapse: collapse;
            text-align: left;
        }

        th, td {
            padding: 1rem 1.25rem;
            border-bottom: 1px solid var(--border-color);
        }

        th {
            background-color: rgba(255, 255, 255, 0.02);
            font-weight: 600;
            color: #ffffff;
            font-size: 0.95rem;
            text-transform: uppercase;
            letter-spacing: 0.5px;
        }

        tr:last-child td {
            border-bottom: none;
        }

        tr:hover td {
            background-color: rgba(255, 255, 255, 0.01);
        }

        .route-cell {
            font-family: 'JetBrains Mono', monospace;
            font-weight: 600;
            color: var(--primary);
            font-size: 1rem;
        }

        .desc-cell {
            font-weight: 400;
            color: #e6edf3;
        }

        .file-cell code {
            font-family: 'JetBrains Mono', monospace;
            color: #ff7b72;
            background-color: var(--code-bg);
            padding: 0.2rem 0.4rem;
            border-radius: 4px;
            font-size: 0.85rem;
        }

        .code-wrapper {
            display: flex;
            align-items: center;
            background-color: var(--code-bg);
            border: 1px solid var(--border-color);
            border-radius: 6px;
            padding: 0.4rem 0.75rem;
            max-width: 480px;
        }

        .code-wrapper code {
            font-family: 'JetBrains Mono', monospace;
            font-size: 0.8rem;
            color: #a5d6ff;
            overflow-x: auto;
            white-space: nowrap;
            flex-grow: 1;
            scrollbar-width: none;
        }
        .code-wrapper code::-webkit-scrollbar {
            display: none;
        }

        .copy-btn {
            background: none;
            border: none;
            color: var(--text-muted);
            cursor: pointer;
            display: flex;
            align-items: center;
            justify-content: center;
            margin-left: 0.5rem;
            padding: 0.25rem;
            border-radius: 4px;
            transition: all 0.2s ease;
        }

        .copy-btn:hover {
            color: #ffffff;
            background-color: var(--border-color);
        }

        .copy-btn.success {
            color: var(--success);
        }

        footer {
            margin-top: 4rem;
            text-align: center;
            color: var(--text-muted);
            font-size: 0.9rem;
            border-top: 1px solid var(--border-color);
            padding-top: 2rem;
        }

        @media (max-width: 768px) {
            body {
                padding: 1rem 0.5rem;
            }
            th, td {
                padding: 0.75rem;
            }
            .code-wrapper {
                max-width: 100%;
            }
        }
    </style>
</head>
<body>
    <div class="container">
        <header>
            <h1>DAA Lab Programs Downloader</h1>
            <p class="subtitle">Quickly download complete C solutions for Design & Analysis of Algorithms Laboratory</p>
        </header>

        <div class="info-card">
            <h3>How to use:</h3>
            <ul>
                <li>To download a program from another computer in the network, execute the <code>curl</code> command listed in the table.</li>
                <li>Ensure the target output filename matches your desired destination.</li>
                <li>The server intercepts <code>POST</code> requests and returns the code files directly.</li>
            </ul>
        </div>

        <div class="table-container">
            <table>
                <thead>
                    <tr>
                        <th style="width: 8%">Sl.</th>
                        <th style="width: 35%">Program Description</th>
                        <th style="width: 22%">Output C File</th>
                        <th style="width: 35%">cURL POST Command</th>
                    </tr>
                </thead>
                <tbody>
                    ${rowsHtml}
                </tbody>
            </table>
        </div>

        <footer>
            <p>Dept. of CSE, R.V. College of Engineering, Bengaluru</p>
        </footer>
    </div>

    <script>
        function copyToClipboard(id) {
            const codeEl = document.getElementById(id);
            const btn = codeEl.nextElementSibling;
            
            navigator.clipboard.writeText(codeEl.textContent).then(() => {
                const originalSvg = btn.innerHTML;
                btn.innerHTML = '<svg xmlns="http://www.w3.org/2000/svg" height="16" viewBox="0 -960 960 960" width="16" fill="currentColor"><path d="M382-240 154-468l57-57 171 171 367-367 57 57-424 424Z"/></svg>';
                btn.classList.add('success');
                
                setTimeout(() => {
                    btn.innerHTML = originalSvg;
                    btn.classList.remove('success');
                }, 2000);
            });
        }
    </script>
</body>
</html>`;
}

const server = http.createServer((req, res) => {
    // Enable CORS
    res.setHeader('Access-Control-Allow-Origin', '*');
    res.setHeader('Access-Control-Allow-Methods', 'GET, POST, OPTIONS');
    res.setHeader('Access-Control-Allow-Headers', 'Content-Type');

    if (req.method === 'OPTIONS') {
        res.writeHead(204);
        res.end();
        return;
    }

    const reqUrl = req.url;

    // Handle POST request to download files
    if (req.method === 'POST') {
        const fileName = fileMap[reqUrl];
        if (fileName) {
            const filePath = path.join(__dirname, 'programs', fileName);
            fs.access(filePath, fs.constants.F_OK, (err) => {
                if (err) {
                    res.writeHead(404, { 'Content-Type': 'text/plain' });
                    res.end('Error: C source file not found on server.');
                } else {
                    res.writeHead(200, {
                        'Content-Type': 'text/x-csrc',
                        'Content-Disposition': `attachment; filename="${fileName}"`
                    });
                    const fileStream = fs.createReadStream(filePath);
                    fileStream.pipe(res);
                }
            });
        } else {
            res.writeHead(404, { 'Content-Type': 'text/plain' });
            res.end('Error: Invalid program code.');
        }
    } 
    // Handle GET requests (Dashboard UI)
    else if (req.method === 'GET') {
        if (reqUrl === '/' || fileMap[reqUrl]) {
            res.writeHead(200, { 'Content-Type': 'text/html' });
            res.end(getDashboardHtml(req.headers.host));
        } else {
            res.writeHead(404, { 'Content-Type': 'text/plain' });
            res.end('404 Not Found');
        }
    } else {
        res.writeHead(405, { 'Content-Type': 'text/plain' });
        res.end('Method Not Allowed');
    }
});

server.listen(PORT, HOST, () => {
    console.log(`=========================================`);
    console.log(`  DAA Downloader Server is now running!`);
    console.log(`  Local:            http://localhost:${PORT}`);
    console.log(`  Network Access:   http://10.70.154.241:${PORT}`);
    console.log(`=========================================`);
});
