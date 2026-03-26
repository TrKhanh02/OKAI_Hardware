// State
let state = {
    ledCount: 30,
    color: '#00ff00',
    effect: 'wave',
    speed: 50,
    brightness: 80,
    mode: 'single',
    isPowerOn: true,
    animationFrame: 0
};

// Presets
const presets = [
    {
        name: 'Party',
        icon: 'party',
        mode: 'rgb',
        effect: 'rainbow',
        color: '#ff0000',
        speed: 80,
        brightness: 100,
        ledCount: 50,
    },
    {
        name: 'Relax',
        icon: 'moon',
        mode: 'single',
        effect: 'breathing',
        color: '#0066ff',
        speed: 20,
        brightness: 40,
        ledCount: 30,
    },
    {
        name: 'Romance',
        icon: 'heart',
        mode: 'single',
        effect: 'fade',
        color: '#ff1493',
        speed: 30,
        brightness: 60,
        ledCount: 40,
    },
    {
        name: 'Energy',
        icon: 'flame',
        mode: 'rgb',
        effect: 'fire',
        color: '#ff6600',
        speed: 60,
        brightness: 90,
        ledCount: 60,
    },
    {
        name: 'Bright',
        icon: 'sun',
        mode: 'single',
        effect: 'static',
        color: '#ffffff',
        speed: 50,
        brightness: 100,
        ledCount: 50,
    },
    {
        name: 'Rainbow',
        icon: 'sparkles',
        mode: 'rgb',
        effect: 'wave',
        color: '#00ff00',
        speed: 50,
        brightness: 80,
        ledCount: 50,
    },
];

// Effect Groups
const effectGroups = [
    {
        name: 'Cơ bản',
        effects: [
            { value: 'static', label: 'Tĩnh', icon: 'circle' },
            { value: 'blink', label: 'Nháy', icon: 'zap' },
            { value: 'breathing', label: 'Hô hấp', icon: 'heart' },
            { value: 'fade', label: 'Mờ dần', icon: 'wind' },
        ],
    },
    {
        name: 'Chuyển động',
        effects: [
            { value: 'wave', label: 'Sóng', icon: 'wave' },
            { value: 'chase', label: 'Đuổi bắt', icon: 'arrow' },
            { value: 'scanner', label: 'Quét', icon: 'scan' },
            { value: 'meteor', label: 'Sao băng', icon: 'star' },
            { value: 'comet', label: 'Sao chổi', icon: 'star' },
            { value: 'colorwipe', label: 'Lau màu', icon: 'paint' },
        ],
    },
    {
        name: 'Đặc biệt',
        effects: [
            { value: 'rainbow', label: 'Cầu vồng', icon: 'rainbow' },
            { value: 'colorchange', label: 'Đổi màu', icon: 'refresh' },
            { value: 'theater', label: 'Rạp hát', icon: 'sparkles' },
            { value: 'fire', label: 'Lửa', icon: 'flame' },
            { value: 'sparkle', label: 'Lấp lánh', icon: 'sparkles' },
            { value: 'fireworks', label: 'Pháo hoa', icon: 'sparkles' },
            { value: 'strobe', label: 'Nhấp nháy', icon: 'zap' },
        ],
    },
];

// Quick Colors
const quickColors = [
    '#FF0000', '#00FF00', '#0000FF',
    '#FFFF00', '#FF00FF', '#00FFFF',
    '#FF8800', '#FF0088', '#8800FF',
    '#88FF00', '#00FF88', '#FFFFFF'
];

// Icons SVG paths (simplified)
const icons = {
    party: '<circle cx="12" cy="12" r="10"/><path d="M12 6v6l4 2"/>',
    moon: '<path d="M21 12.79A9 9 0 1 1 11.21 3 7 7 0 0 0 21 12.79z"/>',
    heart: '<path d="M20.84 4.61a5.5 5.5 0 0 0-7.78 0L12 5.67l-1.06-1.06a5.5 5.5 0 0 0-7.78 7.78l1.06 1.06L12 21.23l7.78-7.78 1.06-1.06a5.5 5.5 0 0 0 0-7.78z"/>',
    flame: '<path d="M8.5 14.5A2.5 2.5 0 0 0 11 12c0-1.38-.5-2-1-3-1.072-2.143-.224-4.054 2-6 .5 2.5 2 4.9 4 6.5 2 1.6 3 3.5 3 5.5a7 7 0 1 1-14 0c0-1.153.433-2.294 1-3a2.5 2.5 0 0 0 2.5 2.5z"/>',
    sun: '<circle cx="12" cy="12" r="5"/><line x1="12" y1="1" x2="12" y2="3"/><line x1="12" y1="21" x2="12" y2="23"/><line x1="4.22" y1="4.22" x2="5.64" y2="5.64"/><line x1="18.36" y1="18.36" x2="19.78" y2="19.78"/><line x1="1" y1="12" x2="3" y2="12"/><line x1="21" y1="12" x2="23" y2="12"/><line x1="4.22" y1="19.78" x2="5.64" y2="18.36"/><line x1="18.36" y1="5.64" x2="19.78" y2="4.22"/>',
    sparkles: '<path d="m12 3-1.912 5.813a2 2 0 0 1-1.275 1.275L3 12l5.813 1.912a2 2 0 0 1 1.275 1.275L12 21l1.912-5.813a2 2 0 0 1 1.275-1.275L21 12l-5.813-1.912a2 2 0 0 1-1.275-1.275L12 3Z"/><path d="M5 3v4"/><path d="M19 17v4"/><path d="M3 5h4"/><path d="M17 19h4"/>',
    circle: '<circle cx="12" cy="12" r="10"/>',
    zap: '<polygon points="13 2 3 14 12 14 11 22 21 10 12 10 13 2"/>',
    wind: '<path d="M9.59 4.59A2 2 0 1 1 11 8H2m10.59 11.41A2 2 0 1 0 14 16H2m15.73-8.27A2.5 2.5 0 1 1 19.5 12H2"/>',
    wave: '<path d="M2 12c.6-2.4 2.4-4 6-4s5.4 1.6 6 4c.6 2.4 2.4 4 6 4"/>',
    arrow: '<line x1="5" y1="12" x2="19" y2="12"/><polyline points="12 5 19 12 12 19"/>',
    scan: '<polyline points="17 11 12 6 7 11"/><polyline points="17 18 12 13 7 18"/>',
    star: '<polygon points="12 2 15.09 8.26 22 9.27 17 14.14 18.18 21.02 12 17.77 5.82 21.02 7 14.14 2 9.27 8.91 8.26 12 2"/>',
    paint: '<path d="M19 11H5"/><path d="M19 7H5"/><path d="M19 15H5"/><rect width="14" height="20" x="5" y="2" rx="2"/>',
    rainbow: '<path d="M22 17a10 10 0 0 0-20 0"/><path d="M6 17a6 6 0 0 1 12 0"/><path d="M10 17a2 2 0 0 1 4 0"/>',
    refresh: '<polyline points="23 4 23 10 17 10"/><path d="M20.49 15a9 9 0 1 1-2.12-9.36L23 10"/>',
};

// Create SVG Icon
function createIcon(iconName, className = 'w-6 h-6') {
    const path = icons[iconName] || icons.circle;
    return `<svg class="${className}" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round">${path}</svg>`;
}

// Initialize
function init() {
    setupModeSelector();
    setupEffectSelector();
    setupColorWheel();
    setupQuickColors();
    setupControls();
    setupPowerButton();
    startAnimation();
}

// Setup Mode Selector
function setupModeSelector() {
    const container = document.getElementById('modeSelector');
    const modes = [
        { value: 'single', label: 'Đơn màu', desc: 'Sử dụng 1 màu', icon: 'circle' },
        { value: 'rgb', label: 'RGB', desc: 'Nhiều màu sắc', icon: 'rainbow' }
    ];

    modes.forEach(mode => {
        const btn = document.createElement('button');
        btn.className = `mode-btn ${state.mode === mode.value ? 'active' : ''}`;
        btn.innerHTML = `
            <div class="mode-icon">${createIcon(mode.icon, 'w-5 h-5')}</div>
            <div class="mode-info">
                <span class="mode-label">${mode.label}</span>
                <span class="mode-desc">${mode.desc}</span>
            </div>
        `;
        btn.onclick = () => {
            state.mode = mode.value;
            updateUI();
        };
        container.appendChild(btn);
    });
}

// Setup Effect Selector
function setupEffectSelector() {
    const container = document.getElementById('effectSelector');
    
    effectGroups.forEach(group => {
        const groupDiv = document.createElement('div');
        groupDiv.className = 'effect-group';
        
        const title = document.createElement('h3');
        title.className = 'effect-group-title';
        title.textContent = group.name;
        groupDiv.appendChild(title);
        
        const grid = document.createElement('div');
        grid.className = 'effect-grid';
        
        group.effects.forEach(effect => {
            const btn = document.createElement('button');
            btn.className = `effect-btn ${state.effect === effect.value ? 'active' : ''}`;
            btn.innerHTML = `
                <div class="effect-icon">${createIcon(effect.icon)}</div>
                <span>${effect.label}</span>
            `;
            btn.onclick = () => {
                state.effect = effect.value;
                updateUI();
            };
            grid.appendChild(btn);
        });
        
        groupDiv.appendChild(grid);
        container.appendChild(groupDiv);
    });
}

// Setup Color Wheel
function setupColorWheel() {
    const canvas = document.getElementById('colorWheel');
    const ctx = canvas.getContext('2d');
    const centerX = canvas.width / 2;
    const centerY = canvas.height / 2;
    const radius = canvas.width / 2 - 10;

    // Draw color wheel
    for (let angle = 0; angle < 360; angle++) {
        const startAngle = (angle - 1) * Math.PI / 180;
        const endAngle = angle * Math.PI / 180;
        
        ctx.beginPath();
        ctx.moveTo(centerX, centerY);
        ctx.arc(centerX, centerY, radius, startAngle, endAngle);
        ctx.closePath();
        
        const gradient = ctx.createRadialGradient(centerX, centerY, 0, centerX, centerY, radius);
        gradient.addColorStop(0, 'white');
        gradient.addColorStop(1, `hsl(${angle}, 100%, 50%)`);
        
        ctx.fillStyle = gradient;
        ctx.fill();
    }

    // Handle click
    canvas.addEventListener('click', (e) => {
        const rect = canvas.getBoundingClientRect();
        const x = e.clientX - rect.left;
        const y = e.clientY - rect.top;
        
        const dx = x - centerX;
        const dy = y - centerY;
        const distance = Math.sqrt(dx * dx + dy * dy);
        
        if (distance <= radius) {
            const angle = Math.atan2(dy, dx) * 180 / Math.PI;
            const hue = (angle + 360) % 360;
            const saturation = (distance / radius) * 100;
            const lightness = 100 - (distance / radius) * 50;
            
            state.color = hslToHex(hue, saturation, lightness);
            updateUI();
        }
    });
}

// HSL to HEX
function hslToHex(h, s, l) {
    l /= 100;
    const a = s * Math.min(l, 1 - l) / 100;
    const f = n => {
        const k = (n + h / 30) % 12;
        const color = l - a * Math.max(Math.min(k - 3, 9 - k, 1), -1);
        return Math.round(255 * color).toString(16).padStart(2, '0');
    };
    return `#${f(0)}${f(8)}${f(4)}`.toUpperCase();
}

// Setup Quick Colors
function setupQuickColors() {
    const container = document.getElementById('quickColors');
    quickColors.forEach(color => {
        const btn = document.createElement('button');
        btn.className = `quick-color-btn ${state.color.toUpperCase() === color ? 'active' : ''}`;
        btn.style.backgroundColor = color;
        btn.onclick = () => {
            state.color = color;
            updateUI();
        };
        container.appendChild(btn);
    });
}

// Setup Controls
function setupControls() {
    const ledCountInput = document.getElementById('ledCountInput');
    const ledCountSlider = document.getElementById('ledCountSlider');
    const speedSlider = document.getElementById('speedSlider');
    const brightnessSlider = document.getElementById('brightnessSlider');

    ledCountInput.addEventListener('input', (e) => {
        let value = parseInt(e.target.value) || 1;
        value = Math.max(1, Math.min(200, value));
        state.ledCount = value;
        updateUI();
    });

    ledCountSlider.addEventListener('input', (e) => {
        state.ledCount = parseInt(e.target.value);
        updateUI();
    });

    speedSlider.addEventListener('input', (e) => {
        state.speed = parseInt(e.target.value);
        updateUI();
    });

    brightnessSlider.addEventListener('input', (e) => {
        state.brightness = parseInt(e.target.value);
        updateUI();
    });
}

// Setup Power Button
function setupPowerButton() {
    const powerBtn = document.getElementById('powerBtn');
    powerBtn.addEventListener('click', () => {
        state.isPowerOn = !state.isPowerOn;
        updateUI();
    });
}

// Update UI
function updateUI() {
    // Update mode selector
    document.querySelectorAll('.mode-btn').forEach((btn, index) => {
        const modes = ['single', 'rgb'];
        btn.className = `mode-btn ${state.mode === modes[index] ? 'active' : ''}`;
    });

    // Update effect selector
    document.querySelectorAll('.effect-btn').forEach(btn => {
        const effectValue = btn.querySelector('span').textContent.toLowerCase();
        const effectMap = {
            'tĩnh': 'static',
            'nháy': 'blink',
            'hô hấp': 'breathing',
            'mờ dần': 'fade',
            'sóng': 'wave',
            'đuổi bắt': 'chase',
            'quét': 'scanner',
            'sao băng': 'meteor',
            'sao chổi': 'comet',
            'lau màu': 'colorwipe',
            'cầu vồng': 'rainbow',
            'đổi màu': 'colorchange',
            'rạp hát': 'theater',
            'lửa': 'fire',
            'lấp lánh': 'sparkle',
            'pháo hoa': 'fireworks',
            'nhấp nháy': 'strobe',
        };
        const mapped = effectMap[effectValue];
        btn.className = `effect-btn ${state.effect === mapped ? 'active' : ''}`;
    });

    // Update quick colors
    document.querySelectorAll('.quick-color-btn').forEach((btn, index) => {
        btn.className = `quick-color-btn ${state.color.toUpperCase() === quickColors[index] ? 'active' : ''}`;
    });

    // Update hex display
    document.getElementById('hexValue').textContent = state.color.toUpperCase();

    // Update controls
    document.getElementById('ledCountInput').value = state.ledCount;
    document.getElementById('ledCountSlider').value = state.ledCount;
    document.getElementById('speedSlider').value = state.speed;
    document.getElementById('brightnessSlider').value = state.brightness;
    document.getElementById('speedValue').textContent = state.speed + '%';
    document.getElementById('brightnessValue').textContent = state.brightness + '%';

    // Update power button
    const powerBtn = document.getElementById('powerBtn');
    powerBtn.className = `power-btn ${state.isPowerOn ? 'power-on' : 'power-off'}`;
    powerBtn.querySelector('.power-text').textContent = state.isPowerOn ? 'BẬT' : 'TẮT';

    // Show/hide color picker based on mode
    const colorPickerCard = document.getElementById('colorPickerCard');
    const controlsCard = document.querySelector('.controls-card');
    if (state.mode === 'single') {
        colorPickerCard.classList.remove('hidden');
        colorPickerCard.style.display = '';
        colorPickerCard.style.position = '';
        colorPickerCard.style.visibility = '';
        colorPickerCard.style.opacity = '';
        colorPickerCard.style.pointerEvents = '';
        controlsCard.classList.remove('full-width');
    } else {
        colorPickerCard.classList.add('hidden');
        controlsCard.classList.add('full-width');
    }
}

// LED Animation
function startAnimation() {
    function animate() {
        state.animationFrame++;
        renderLEDs();
        requestAnimationFrame(animate);
    }
    animate();
}

function renderLEDs() {
    const container = document.getElementById('ledPreview');
    const currentLEDCount = container.children.length;

    // Add or remove LEDs to match count
    if (currentLEDCount < state.ledCount) {
        for (let i = currentLEDCount; i < state.ledCount; i++) {
            const led = document.createElement('div');
            led.className = 'led';
            container.appendChild(led);
        }
    } else if (currentLEDCount > state.ledCount) {
        for (let i = currentLEDCount - 1; i >= state.ledCount; i--) {
            container.removeChild(container.children[i]);
        }
    }

    // Update each LED
    for (let i = 0; i < state.ledCount; i++) {
        const led = container.children[i];
        const style = getLEDStyle(i);
        Object.assign(led.style, style);
    }
}

function getLEDStyle(index) {
    const baseOpacity = state.brightness / 100;
    const frameSpeed = state.speed / 10;
    const animationFrame = Math.floor(state.animationFrame * frameSpeed / 5);

    if (!state.isPowerOn) {
        return {
            backgroundColor: '#333',
            opacity: 0.1,
            boxShadow: 'none',
        };
    }

    const getColor = (idx, hueOffset = 0) => {
        if (state.mode === 'rgb') {
            const hue = (idx * 360 / state.ledCount + hueOffset) % 360;
            return `hsl(${hue}, 100%, 50%)`;
        }
        return state.color;
    };

    switch (state.effect) {
        case 'static':
            const staticColor = getColor(index);
            return {
                backgroundColor: staticColor,
                opacity: baseOpacity,
                boxShadow: `0 0 10px ${staticColor}, 0 0 20px ${staticColor}`,
            };

        case 'blink':
            const blinkOn = animationFrame % 10 < 5;
            const blinkColor = getColor(index);
            return {
                backgroundColor: blinkColor,
                opacity: blinkOn ? baseOpacity : 0.1,
                boxShadow: blinkOn ? `0 0 15px ${blinkColor}, 0 0 30px ${blinkColor}` : 'none',
            };

        case 'breathing':
            const breathCycle = (Math.sin(animationFrame / 8) + 1) / 2;
            const breathColor = getColor(index, animationFrame * 3);
            const breathOpacity = (breathCycle * 0.8 + 0.2) * baseOpacity;
            return {
                backgroundColor: breathColor,
                opacity: breathOpacity,
                boxShadow: `0 0 ${15 * breathCycle}px ${breathColor}, 0 0 ${30 * breathCycle}px ${breathColor}`,
            };

        case 'fade':
            const fadeCycle = (Math.sin(animationFrame / 10) + 1) / 2;
            const fadeColor = getColor(index, animationFrame * 5);
            return {
                backgroundColor: fadeColor,
                opacity: fadeCycle * baseOpacity,
                boxShadow: fadeCycle > 0.5 ? `0 0 15px ${fadeColor}` : 'none',
            };

        case 'wave':
            const wavePhase = (index / state.ledCount) * Math.PI * 2;
            const waveValue = (Math.sin(animationFrame / 5 + wavePhase) + 1) / 2;
            const waveColor = getColor(index, animationFrame * 10);
            return {
                backgroundColor: waveColor,
                opacity: (waveValue * 0.8 + 0.2) * baseOpacity,
                boxShadow: waveValue > 0.7 ? `0 0 20px ${waveColor}, 0 0 40px ${waveColor}` : 'none',
            };

        case 'chase':
            const chasePos = animationFrame % state.ledCount;
            const isChaseActive = index === chasePos;
            const chaseColor = getColor(index, animationFrame * 15);
            return {
                backgroundColor: chaseColor,
                opacity: isChaseActive ? baseOpacity : 0.2,
                boxShadow: isChaseActive ? `0 0 20px ${chaseColor}, 0 0 40px ${chaseColor}` : 'none',
            };

        case 'rainbow':
            const rainbowHue = (index * 360 / state.ledCount + animationFrame * 5) % 360;
            const rainbowColor = `hsl(${rainbowHue}, 100%, 50%)`;
            return {
                backgroundColor: rainbowColor,
                opacity: baseOpacity,
                boxShadow: `0 0 15px ${rainbowColor}`,
            };

        case 'sparkle':
            const isSparkle = Math.random() < 0.05;
            const sparkleColor = getColor(index, Math.random() * 360);
            return {
                backgroundColor: sparkleColor,
                opacity: isSparkle ? baseOpacity : 0.2,
                boxShadow: isSparkle ? `0 0 25px ${sparkleColor}, 0 0 50px ${sparkleColor}` : 'none',
            };

        case 'colorchange':
            const changeOn = animationFrame % 2 === 0;
            const hueShift = (animationFrame * 30) % 360;
            let changeColor;
            if (state.mode === 'rgb') {
                const baseHue = (index * 360 / state.ledCount) % 360;
                changeColor = `hsl(${(baseHue + hueShift) % 360}, 100%, 50%)`;
            } else {
                changeColor = `hsl(${hueShift}, 100%, 50%)`;
            }
            return {
                backgroundColor: changeColor,
                opacity: changeOn ? baseOpacity : 0.1,
                boxShadow: changeOn ? `0 0 15px ${changeColor}, 0 0 30px ${changeColor}` : 'none',
            };

        case 'strobe':
            const strobeOn = animationFrame % 4 < 1;
            const strobeColor = getColor(index, animationFrame * 50);
            return {
                backgroundColor: strobeColor,
                opacity: strobeOn ? baseOpacity : 0,
                boxShadow: strobeOn ? `0 0 20px ${strobeColor}, 0 0 40px ${strobeColor}` : 'none',
            };

        case 'theater':
            const theaterGroup = index % 3;
            const theaterActive = (animationFrame % 3) === theaterGroup;
            const theaterColor = getColor(index, animationFrame * 20);
            return {
                backgroundColor: theaterColor,
                opacity: theaterActive ? baseOpacity : 0.1,
                boxShadow: theaterActive ? `0 0 15px ${theaterColor}, 0 0 30px ${theaterColor}` : 'none',
            };

        case 'fire':
            const flicker = Math.random() * 0.5 + 0.5;
            const fireHue = state.mode === 'rgb' ? (index * 60 / state.ledCount) : 0;
            const fireColor = `hsl(${fireHue + 20}, 100%, ${30 + flicker * 20}%)`;
            return {
                backgroundColor: fireColor,
                opacity: baseOpacity * flicker,
                boxShadow: `0 0 ${10 * flicker}px ${fireColor}, 0 0 ${20 * flicker}px ${fireColor}`,
            };

        case 'meteor':
            const meteorPos = animationFrame % (state.ledCount + 10);
            const meteorDistance = Math.abs(index - meteorPos);
            const meteorIntensity = Math.max(0, 1 - meteorDistance / 5);
            const meteorColor = getColor(index, animationFrame * 15);
            return {
                backgroundColor: meteorColor,
                opacity: meteorIntensity * baseOpacity,
                boxShadow: meteorIntensity > 0.3 ? `0 0 ${15 * meteorIntensity}px ${meteorColor}` : 'none',
            };

        case 'scanner':
            const scannerPos = animationFrame % (state.ledCount * 2);
            const scannerIndex = scannerPos < state.ledCount ? scannerPos : (state.ledCount * 2 - scannerPos - 1);
            const scannerDist = Math.abs(index - scannerIndex);
            const scannerBright = Math.max(0, 1 - scannerDist / 3);
            const scannerColor = getColor(scannerIndex, 0);
            return {
                backgroundColor: scannerColor,
                opacity: scannerBright * baseOpacity,
                boxShadow: scannerBright > 0.5 ? `0 0 20px ${scannerColor}, 0 0 40px ${scannerColor}` : 'none',
            };

        case 'comet':
            const cometPos = animationFrame % (state.ledCount + 15);
            const cometDist = index - cometPos;
            const cometTail = cometDist >= 0 && cometDist < 8 ? (1 - cometDist / 8) : 0;
            const cometColor = getColor(index, animationFrame * 10);
            return {
                backgroundColor: cometColor,
                opacity: cometTail * baseOpacity,
                boxShadow: cometTail > 0.6 ? `0 0 20px ${cometColor}, 0 0 40px ${cometColor}` : 'none',
            };

        case 'fireworks':
            const burstChance = Math.random() < 0.05;
            const burstColor = getColor(index, Math.floor(Math.random() * 360));
            const currentBurst = burstChance ? baseOpacity : Math.max(0, (animationFrame % 10) / 10);
            return {
                backgroundColor: burstColor,
                opacity: burstChance ? baseOpacity : currentBurst * 0.3,
                boxShadow: burstChance ? `0 0 25px ${burstColor}, 0 0 50px ${burstColor}` : 'none',
            };

        case 'colorwipe':
            const wipePos = (animationFrame * 2) % (state.ledCount * 2);
            const wipeColor = getColor(index, animationFrame * 5);
            const isWiped = wipePos < state.ledCount ? index < wipePos : index >= (state.ledCount * 2 - wipePos);
            return {
                backgroundColor: wipeColor,
                opacity: isWiped ? baseOpacity : 0.1,
                boxShadow: isWiped ? `0 0 10px ${wipeColor}, 0 0 20px ${wipeColor}` : 'none',
            };

        default:
            return {
                backgroundColor: state.color,
                opacity: baseOpacity,
            };
    }
}

// Start the app
init();